#pragma once
#include "Interop.h"
#include "InteropApp.h"

namespace Toybox::Interop
{
    void InteropApp::OnOpen()
    {
        TBX_TRACE("OnOpen called!");
    }

    void InteropApp::OnUpdate()
    {
        TBX_INFO("Update called!");
        TBX_WARN("Frame: {}", _frameCount);
        _frameCount++;
    }

    void InteropApp::OnClose()
    {
        TBX_TRACE("OnClose called!");
    }
}