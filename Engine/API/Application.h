#pragma once
#include <string>
#include "ToyboxAPI.h"
#include "Modules/Windows/IWindow.h"

namespace Toybox
{
    class TOYBOX_API Application
    {
    public:
        Application(const std::string& name);
        virtual ~Application();
        void Launch();
        void Update();
        void Close();
        int GetHandle();
        bool GetIsRunning();
        Modules::IWindow* GetMainWindow();

    protected:
        virtual void OnOpen() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnClose() = 0;
    };

    // API to create app, meant to be defined in CLIENT!
    extern Application* CreateApp();
}
