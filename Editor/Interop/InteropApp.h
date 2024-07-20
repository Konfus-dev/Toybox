#pragma once
#include <Toybox.h>
#include "InteropApp.h"
#include "InteropAPI.h"

namespace Toybox::Interop
{
    class InteropApp : public Application::App
    {
    public:
        InteropApp() : Application::App("Toybox") { }
        ~InteropApp() = default;

    protected:
        void OnOpen() override;
        void OnUpdate() override;
        void OnClose() override;

    private:
        int _frameCount = 0;
    };
}