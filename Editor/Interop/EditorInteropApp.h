#pragma once

#include <Toybox.h>
#include "EditorInteropApp.h"

namespace EditorInterop
{
    class EditorInteropApp : public Toybox::Application::App
    {
    public:
        EditorInteropApp() : Toybox::Application::App("Toybox") { }
        ~EditorInteropApp() = default;

    protected:
        void OnOpen() override;
        void OnUpdate() override;
        void OnClose() override;

    private:
        int _frameCount = 0;
    };
}