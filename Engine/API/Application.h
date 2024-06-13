#pragma once
#include <string>
#include "ToyboxAPI.h"
#include "Modules/RenderSurfaces/IWindow.h"

namespace Toybox
{
    class TOYBOX_API Application
    {
    public:
        Application(std::string name);
        virtual ~Application();
        void Launch();
        void Close();
        int GetHandle();

    protected:
        virtual void OnOpen() = 0;
        virtual void Update() = 0;
        virtual void OnClose() = 0;
    };

    // API to create app, meant to be defined in CLIENT!
    extern Application* CreateApp();
}
