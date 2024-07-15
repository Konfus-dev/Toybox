#pragma once
#include "EditorCoreInteropAPI.h"
#include "EditorInteropApp.h"

TBX_EDITOR_CORE_INTEROP_API int LaunchViewport()
{
    return EditorCoreApp->GetMainWindow()->GetHandle();
}