#include "framework.h" 
#include <cassert>
#include <vector>

#include "ErrorMsg.D3D.h"

using namespace std;

#define ADD messages.emplace_back

namespace common::errormsg::d3d {
    vector<ErrorMessage> messages;
    ON_INIT{
        ADD(0x8876017c, "D3DERR_OUTOFVIDEOMEMORY", nullptr, "d3d9.h");
        ADD(0x8876021c, "D3DERR_WASSTILLDRAWING", nullptr, "d3d9.h");
        ADD(0x887602bc, "D3DERR_BADMAJORVERSION", nullptr, "d3d.h");
        ADD(0x887602bd, "D3DERR_BADMINORVERSION", nullptr, "d3d.h");
        ADD(0x887602c1, "D3DERR_INVALID_DEVICE", nullptr, "d3d.h");
        ADD(0x887602c2, "D3DERR_INITFAILED", nullptr, "d3d.h");
        ADD(0x887602c3, "D3DERR_DEVICEAGGREGATED", nullptr, "d3d.h");
        ADD(0x887602c6, "D3DERR_EXECUTE_CREATE_FAILED", nullptr, "d3d.h");
        ADD(0x887602c7, "D3DERR_EXECUTE_DESTROY_FAILED", nullptr, "d3d.h");
        ADD(0x887602c8, "D3DERR_EXECUTE_LOCK_FAILED", nullptr, "d3d.h");
        ADD(0x887602c9, "D3DERR_EXECUTE_UNLOCK_FAILED", nullptr, "d3d.h");
        ADD(0x887602ca, "D3DERR_EXECUTE_LOCKED", nullptr, "d3d.h");
        ADD(0x887602cb, "D3DERR_EXECUTE_NOT_LOCKED", nullptr, "d3d.h");
        ADD(0x887602cc, "D3DERR_EXECUTE_FAILED", nullptr, "d3d.h");
        ADD(0x887602cd, "D3DERR_EXECUTE_CLIPPED_FAILED", nullptr, "d3d.h");
        ADD(0x887602d0, "D3DERR_TEXTURE_NO_SUPPORT", nullptr, "d3d.h");
        ADD(0x887602d1, "D3DERR_TEXTURE_CREATE_FAILED", nullptr, "d3d.h");
        ADD(0x887602d2, "D3DERR_TEXTURE_DESTROY_FAILED", nullptr, "d3d.h");
        ADD(0x887602d3, "D3DERR_TEXTURE_LOCK_FAILED", nullptr, "d3d.h");
        ADD(0x887602d4, "D3DERR_TEXTURE_UNLOCK_FAILED", nullptr, "d3d.h");
        ADD(0x887602d5, "D3DERR_TEXTURE_LOAD_FAILED", nullptr, "d3d.h");
        ADD(0x887602d6, "D3DERR_TEXTURE_SWAP_FAILED", nullptr, "d3d.h");
        ADD(0x887602d7, "D3DERR_TEXTURE_LOCKED", nullptr, "d3d.h");
        ADD(0x887602d8, "D3DERR_TEXTURE_NOT_LOCKED", nullptr, "d3d.h");
        ADD(0x887602d9, "D3DERR_TEXTURE_GETSURF_FAILED", nullptr, "d3d.h");
        ADD(0x887602da, "D3DERR_MATRIX_CREATE_FAILED", nullptr, "d3d.h");
        ADD(0x887602db, "D3DERR_MATRIX_DESTROY_FAILED", nullptr, "d3d.h");
        ADD(0x887602dc, "D3DERR_MATRIX_SETDATA_FAILED", nullptr, "d3d.h");
        ADD(0x887602dd, "D3DERR_MATRIX_GETDATA_FAILED", nullptr, "d3d.h");
        ADD(0x887602de, "D3DERR_SETVIEWPORTDATA_FAILED", nullptr, "d3d.h");
        ADD(0x887602df, "D3DERR_INVALIDCURRENTVIEWPORT", nullptr, "d3d.h");
        ADD(0x887602e0, "D3DERR_INVALIDPRIMITIVETYPE", nullptr, "d3d.h");
        ADD(0x887602e1, "D3DERR_INVALIDVERTEXTYPE", nullptr, "d3d.h");
        ADD(0x887602e2, "D3DERR_TEXTURE_BADSIZE", nullptr, "d3d.h");
        ADD(0x887602e3, "D3DERR_INVALIDRAMPTEXTURE", nullptr, "d3d.h");
        ADD(0x887602e4, "D3DERR_MATERIAL_CREATE_FAILED", nullptr, "d3d.h");
        ADD(0x887602e5, "D3DERR_MATERIAL_DESTROY_FAILED", nullptr, "d3d.h");
        ADD(0x887602e6, "D3DERR_MATERIAL_SETDATA_FAILED", nullptr, "d3d.h");
        ADD(0x887602e7, "D3DERR_MATERIAL_GETDATA_FAILED", nullptr, "d3d.h");
        ADD(0x887602e8, "D3DERR_INVALIDPALETTE", nullptr, "d3d.h");
        ADD(0x887602e9, "D3DERR_ZBUFF_NEEDS_SYSTEMMEMORY", nullptr, "d3d.h");
        ADD(0x887602ea, "D3DERR_ZBUFF_NEEDS_VIDEOMEMORY", nullptr, "d3d.h");
        ADD(0x887602eb, "D3DERR_SURFACENOTINVIDMEM", nullptr, "d3d.h");
        ADD(0x887602ee, "D3DERR_LIGHT_SET_FAILED", nullptr, "d3d.h");
        ADD(0x887602ef, "D3DERR_LIGHTHASVIEWPORT", nullptr, "d3d.h");
        ADD(0x887602f0, "D3DERR_LIGHTNOTINTHISVIEWPORT", nullptr, "d3d.h");
        ADD(0x887602f8, "D3DERR_SCENE_IN_SCENE", nullptr, "d3d.h");
        ADD(0x887602f9, "D3DERR_SCENE_NOT_IN_SCENE", nullptr, "d3d.h");
        ADD(0x887602fa, "D3DERR_SCENE_BEGIN_FAILED", nullptr, "d3d.h");
        ADD(0x887602fb, "D3DERR_SCENE_END_FAILED", nullptr, "d3d.h");
        ADD(0x88760302, "D3DERR_INBEGIN", nullptr, "d3d.h");
        ADD(0x88760303, "D3DERR_NOTINBEGIN", nullptr, "d3d.h");
        ADD(0x88760304, "D3DERR_NOVIEWPORTS", nullptr, "d3d.h");
        ADD(0x88760305, "D3DERR_VIEWPORTDATANOTSET", nullptr, "d3d.h");
        ADD(0x88760306, "D3DERR_VIEWPORTHASNODEVICE", nullptr, "d3d.h");
        ADD(0x88760307, "D3DERR_NOCURRENTVIEWPORT", nullptr, "d3d.h");
        ADD(0x88760384, "D3DXFERR_BADOBJECT", nullptr, "d3dx9xof.h");
        ADD(0x88760385, "D3DXFERR_BADVALUE", nullptr, "d3dx9xof.h");
        ADD(0x88760386, "D3DXFERR_BADTYPE", nullptr, "d3dx9xof.h");
        ADD(0x88760387, "D3DXFERR_NOTFOUND", nullptr, "d3dx9xof.h");
        ADD(0x88760388, "D3DXFERR_NOTDONEYET", nullptr, "d3dx9xof.h");
        ADD(0x88760389, "D3DXFERR_FILENOTFOUND", nullptr, "d3dx9xof.h");
        ADD(0x8876038a, "D3DXFERR_RESOURCENOTFOUND", nullptr, "d3dx9xof.h");
        ADD(0x8876038b, "D3DXFERR_BADRESOURCE", nullptr, "d3dx9xof.h");
        ADD(0x8876038c, "D3DXFERR_BADFILETYPE", nullptr, "d3dx9xof.h");
        ADD(0x8876038d, "D3DXFERR_BADFILEVERSION", nullptr, "d3dx9xof.h");
        ADD(0x8876038e, "D3DXFERR_BADFILEFLOATSIZE", nullptr, "d3dx9xof.h");
        ADD(0x8876038f, "D3DXFERR_BADFILE", nullptr, "d3dx9xof.h");
        ADD(0x88760390, "D3DXFERR_PARSEERROR", nullptr, "d3dx9xof.h");
        ADD(0x88760391, "D3DXFERR_BADARRAYSIZE", nullptr, "d3dx9xof.h");
        ADD(0x88760392, "D3DXFERR_BADDATAREFERENCE", nullptr, "d3dx9xof.h");
        ADD(0x88760393, "D3DXFERR_NOMOREOBJECTS", nullptr, "d3dx9xof.h");
        ADD(0x88760394, "D3DXFERR_NOMOREDATA", nullptr, "d3dx9xof.h");
        ADD(0x88760395, "D3DXFERR_BADCACHEFILE", nullptr, "d3dx9xof.h");
        ADD(0x88760800, "D3DERR_INVALIDVERTEXFORMAT", nullptr, "d3d.h");
        ADD(0x88760802, "D3DERR_COLORKEYATTACHED", nullptr, "d3d.h");
        ADD(0x8876080c, "D3DERR_VERTEXBUFFEROPTIMIZED", nullptr, "d3d.h");
        ADD(0x8876080d, "D3DERR_VBUF_CREATE_FAILED", nullptr, "d3d.h");
        ADD(0x8876080e, "D3DERR_VERTEXBUFFERLOCKED", nullptr, "d3d.h");
        ADD(0x8876080f, "D3DERR_VERTEXBUFFERUNLOCKFAILED", nullptr, "d3d.h");
        ADD(0x88760816, "D3DERR_ZBUFFER_NOTPRESENT", nullptr, "d3d.h");
        ADD(0x88760817, "D3DERR_STENCILBUFFER_NOTPRESENT", nullptr, "d3d.h");
        ADD(0x88760818, "D3DERR_WRONGTEXTUREFORMAT", nullptr, "d3d.h");
        ADD(0x88760819, "D3DERR_UNSUPPORTEDCOLOROPERATION", nullptr, "d3d.h");
        ADD(0x8876081a, "D3DERR_UNSUPPORTEDCOLORARG", nullptr, "d3d.h");
        ADD(0x8876081b, "D3DERR_UNSUPPORTEDALPHAOPERATION", nullptr, "d3d.h");
        ADD(0x8876081c, "D3DERR_UNSUPPORTEDALPHAARG", nullptr, "d3d.h");
        ADD(0x8876081d, "D3DERR_TOOMANYOPERATIONS", nullptr, "d3d.h");
        ADD(0x8876081e, "D3DERR_CONFLICTINGTEXTUREFILTER", nullptr, "d3d.h");
        ADD(0x8876081f, "D3DERR_UNSUPPORTEDFACTORVALUE", nullptr, "d3d.h");
        ADD(0x88760821, "D3DERR_CONFLICTINGRENDERSTATE", nullptr, "d3d.h");
        ADD(0x88760822, "D3DERR_UNSUPPORTEDTEXTUREFILTER", nullptr, "d3d.h");
        ADD(0x88760823, "D3DERR_TOOMANYPRIMITIVES", nullptr, "d3d.h");
        ADD(0x88760824, "D3DERR_INVALIDMATRIX", nullptr, "d3d.h");
        ADD(0x88760825, "D3DERR_TOOMANYVERTICES", nullptr, "d3d.h");
        ADD(0x88760826, "D3DERR_CONFLICTINGTEXTUREPALETTE", nullptr, "d3d.h");
        ADD(0x88760827, "D3DERR_DRIVERINTERNALERROR", nullptr, "d3d9.h");
        ADD(0x88760834, "D3DERR_INVALIDSTATEBLOCK", nullptr, "d3d.h");
        ADD(0x88760835, "D3DERR_INBEGINSTATEBLOCK", nullptr, "d3d.h");
        ADD(0x88760836, "D3DERR_NOTINBEGINSTATEBLOCK", nullptr, "d3d.h");
        ADD(0x88760866, "D3DERR_NOTFOUND", nullptr, "d3d9.h");
        ADD(0x88760867, "D3DERR_MOREDATA", nullptr, "d3d9.h");
        ADD(0x88760868, "D3DERR_DEVICELOST", nullptr, "d3d9.h");
        ADD(0x88760869, "D3DERR_DEVICENOTRESET", nullptr, "d3d9.h");
        ADD(0x8876086a, "D3DERR_NOTAVAILABLE", nullptr, "d3d9.h");
        ADD(0x8876086b, "D3DERR_INVALIDDEVICE", nullptr, "d3d9.h");
        ADD(0x8876086c, "D3DERR_INVALIDCALL", nullptr, "d3d9.h");
        ADD(0x8876086d, "D3DERR_DRIVERINVALIDCALL", nullptr, "d3d9.h");
        ADD(0x88760870, "D3DERR_DEVICEREMOVED", nullptr, "d3d9.h");
        ADD(0x88760874, "D3DERR_DEVICEHUNG", nullptr, "d3d9.h");
        ADD(0x8876087b, "D3DERR_UNSUPPORTEDOVERLAY", nullptr, "d3d9.h");
        ADD(0x8876087c, "D3DERR_UNSUPPORTEDOVERLAYFORMAT", nullptr, "d3d9.h");
        ADD(0x8876087d, "D3DERR_CANNOTPROTECTCONTENT", nullptr, "d3d9.h");
        ADD(0x8876087e, "D3DERR_UNSUPPORTEDCRYPTO", nullptr, "d3d9.h");
        ADD(0x88760884, "D3DERR_PRESENT_STATISTICS_DISJOINT", nullptr, "d3d9.h");
        ADD(0x88760b54, "D3DXERR_CANNOTMODIFYINDEXBUFFER", nullptr, "d3dx9.h");
        ADD(0x88760b55, "D3DXERR_INVALIDMESH", nullptr, "d3dx9.h");
        ADD(0x88760b56, "D3DXERR_CANNOTATTRSORT", nullptr, "d3dx9.h");
        ADD(0x88760b57, "D3DXERR_SKINNINGNOTSUPPORTED", nullptr, "d3dx9.h");
        ADD(0x88760b58, "D3DXERR_TOOMANYINFLUENCES", nullptr, "d3dx9.h");
        ADD(0x88760b59, "D3DXERR_INVALIDDATA", nullptr, "d3dx9.h");
        ADD(0x88760b5a, "D3DXERR_LOADEDMESHASNODATA", nullptr, "d3dx9.h");
        ADD(0x88760b5b, "D3DXERR_DUPLICATENAMEDFRAGMENT", nullptr, "d3dx9.h");
        ADD(0x88760b5c, "D3DXERR_CANNOTREMOVELASTITEM", nullptr, "d3dx9.h");
    };
    ON_INIT{
        for (size_t i = 1; i < messages.size(); i++) {
            assert(messages[i - 1].code <= messages[i].code);
        }
    };
}