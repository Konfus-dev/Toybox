#include "EditorCoreInterop.h"

// TODO: The viewport should be owned by the EditorCore app
// need to move to the messaging system first, otherwise we will get errors trying to access stuff owned by other threads
Toybox::Application* Viewport;
TBX_EDITOR_CORE_INTEROP_API int LaunchViewport()
{
    // TODO: Instead use messages to grab the instances handle.
    TBX_INFO("Launching Editor!");
    Viewport = Toybox::CreateApp();
    Viewport->Launch();
    return Viewport->GetMainWindow()->GetHandle();
}

TBX_EDITOR_CORE_INTEROP_API void UpdateViewport()
{
    TBX_INFO("Updating viewport!");
    Viewport->GetMainWindow()->Update();
}