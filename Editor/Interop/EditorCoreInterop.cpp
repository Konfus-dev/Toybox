#include "EditorCoreInterop.h"

// TODO: The viewport should be owned by the EditorCore app
// need to move to the messaging system first, otherwise we will get errors trying to access stuff owned by other threads
TBX_EDITOR_CORE_INTEROP_API int LaunchViewport()
{
    // TODO: Use messages to grab the instances handle.
}

TBX_EDITOR_CORE_INTEROP_API void UpdateViewport()
{
}