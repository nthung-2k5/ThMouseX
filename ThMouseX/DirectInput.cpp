#include "framework.h"
#include <dinput.h>
#include <string>
#include <vector>
#include <wrl/client.h>
#include <mutex>

#include "../Common/macro.h"
#include "../Common/DataTypes.h"
#include "../Common/Variables.h"
#include "../Common/MinHook.h"
#include "../Common/Log.h"
#include "../Common/Helper.h"
#include "InputDetermine.h"
#include "DirectInput.h"

namespace minhook = common::minhook;
namespace note = common::log;
namespace helper = common::helper;

constexpr auto GetDeviceStateIdx = 9;

using namespace std;
using namespace core::inputdetermine;
using namespace Microsoft::WRL;

#define TAG "[DirectInput] "

namespace core::directinput {
    HRESULT WINAPI GetDeviceStateDInput8(IDirectInputDevice8A* pDevice, DWORD cbData, LPVOID lpvData);
    decltype(&GetDeviceStateDInput8) OriGetDeviceStateDInput8;

    void Initialize() {
        static bool initialized = false;
        static mutex mtx;
        HMODULE dinput8{};
        {
            const lock_guard lock(mtx);
            if (initialized)
                return;
            if ((g_currentConfig.InputMethods & InputMethod::DirectInput) == InputMethod::None)
                return;
            dinput8 = GetModuleHandleW((g_systemDirPath + wstring(L"\\DInput8.dll")).c_str());
            if (!dinput8)
                return;
            initialized = true;
        }

        auto _DirectInput8Create = (decltype(&DirectInput8Create))GetProcAddress(dinput8, "DirectInput8Create");
        if (!_DirectInput8Create) {
            note::LastErrorToFile(TAG "Failed to import DInput8.dll|DirectInput8Create.");
            return;
        }

        ComPtr<IDirectInput8A> pDInput8;
        auto rs = _DirectInput8Create(GetModuleHandleA(NULL), DIRECTINPUT_VERSION, IID_IDirectInput8A, (PVOID*)&pDInput8, NULL);
        if (FAILED(rs)) {
            note::DxErrToFile(TAG "Failed to create an IDirectInput8 instance", rs);
            return;
        }

        ComPtr<IDirectInputDevice8A> pDevice8;
        rs = pDInput8->CreateDevice(GUID_SysKeyboard, &pDevice8, NULL);
        if (FAILED(rs)) {
            note::DxErrToFile(TAG "Failed to create an IDirectInputDevice8 instance", rs);
            return;
        }

        auto vtable = *(DWORD**)pDevice8.Get();
        auto baseAddress = (DWORD)dinput8;

        minhook::CreateHook(vector<minhook::HookConfig>{
            {PVOID(vtable[GetDeviceStateIdx]), &GetDeviceStateDInput8, (PVOID*)&OriGetDeviceStateDInput8},
        });
    }

    HRESULT WINAPI GetDeviceStateDInput8(IDirectInputDevice8A* pDevice, DWORD cbData, LPVOID lpvData) {
        auto hr = OriGetDeviceStateDInput8(pDevice, cbData, lpvData);
        if (SUCCEEDED(hr) && cbData == sizeof(BYTE) * 256) {
            auto keys = PBYTE(lpvData);
            auto gameInput = DetermineGameInput();
            if ((gameInput & GameInput::USE_BOMB) == GameInput::USE_BOMB)
                keys[DIK_X] |= 0x80;
            if ((gameInput & GameInput::USE_SPECIAL) == GameInput::USE_SPECIAL)
                keys[DIK_C] |= 0x80;
            if ((gameInput & GameInput::MOVE_LEFT) == GameInput::MOVE_LEFT)
                keys[DIK_LEFT] |= 0x80;
            if ((gameInput & GameInput::MOVE_RIGHT) == GameInput::MOVE_RIGHT)
                keys[DIK_RIGHT] |= 0x80;
            if ((gameInput & GameInput::MOVE_UP) == GameInput::MOVE_UP)
                keys[DIK_UP] |= 0x80;
            if ((gameInput & GameInput::MOVE_DOWN) == GameInput::MOVE_DOWN)
                keys[DIK_DOWN] |= 0x80;
        }
        return hr;
    }
}
