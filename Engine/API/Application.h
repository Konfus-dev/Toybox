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
        std::string GetName();

    protected:
        virtual void OnOpen() = 0;
        virtual void Update() = 0;
        virtual void OnClose() = 0; 

    private:
        bool _isOpen;
        std::string _name;
        Modules::IWindow* _mainWindow;
    };

    // API to create app, meant to be defined in CLIENT!
    extern Application* CreateApp();
}
