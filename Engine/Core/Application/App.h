#pragma once

#include "tbxpch.h"
#include "IWindow.h"
#include "ToyboxAPI.h"
#include "Events/Events.h"

namespace Toybox::Application
{
    class TOYBOX_API App
    {
    // Public lifetime methods
    public:
        App(const std::string& name);
        virtual ~App();
        void Launch();
        void Update();
        void Close();
    // Public getters and setters
    public:
        const bool IsRunning();
        const std::string& GetName();
        const IWindow* GetMainWindow();
    // Protected lifetime methods
    protected:
        virtual void OnOpen() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnClose() = 0;
    // Private lifetime methods
    private:
        bool OnWindowClose(Events::WindowCloseEvent& e);
        void OnEvent(Events::Event& e);
    };

    // API to create app, meant to be defined in CLIENT!
    extern App* CreateApp();
}
