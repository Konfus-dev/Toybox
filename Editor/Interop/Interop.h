#pragma once
#include "InteropAPI.h"
#include "InteropApp.h"

static Toybox::Interop::InteropApp* EditorCoreApp;
TBX_EDITOR_CORE_API int LaunchViewport()
{
    return EditorCoreApp->GetMainWindow()->GetHandle();
}

Toybox::Application::App* Toybox::Application::CreateApp()
{
    EditorCoreApp = new Toybox::Interop::InteropApp();
    return EditorCoreApp;
}