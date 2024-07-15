#pragma once
#include "EditorInteropApp.h"

namespace EditorInterop
{
    void EditorInteropApp::OnOpen()
    {
        TBX_TRACE("OnOpen called!");
    }

    void EditorInteropApp::OnUpdate()
    {
        TBX_INFO("Update called!");
        TBX_WARN("Frame: {}", _frameCount++);
    }

    void EditorInteropApp::OnClose()
    {
        TBX_TRACE("OnClose called!");
    }
}

static EditorInterop::EditorInteropApp* EditorCoreApp;
Toybox::Application::App* Toybox::Application::CreateApp()
{
    TBX_INFO("Created editor!");
    EditorCoreApp = new EditorInterop::EditorInteropApp();
    return EditorCoreApp;
}