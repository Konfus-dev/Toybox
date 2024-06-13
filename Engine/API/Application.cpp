#include "tbxpch.h"
#include "Application.h"
#include "Modules/RenderSurfaces/WindowFactory.h"

namespace Toybox
{
    bool _isOpen;
    std::string _name;
    Modules::IWindow* _mainWindow;

    Application::Application(const std::string name)
    {
        _name = name;
        _isOpen = false;
        _mainWindow = Modules::WindowFactory::Create(name, new Math::Size(1920, 1080));
    }

    Application::~Application()
    {
        if (_isOpen) Close();
        delete _mainWindow;
    }
    
    void Application::Launch()
    {
        _isOpen = true;
        OnOpen();
        while (_isOpen) 
        {
            Update();
            _mainWindow->Update();
        }
    }

    void Application::Close()
    {
        _isOpen = false;
    }

    int Application::GetHandle()
    {
        return _mainWindow->GetHandle();
    }
}
