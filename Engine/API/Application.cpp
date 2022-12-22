#include "tbxpch.h"
#include "Application.h"
#include "Modules/RenderSurfaces/WindowFactory.h"

namespace Toybox
{
    Application::Application(const std::string name)
    {
        _name = name;
        _isOpen = false;
        _window = Modules::WindowFactory::Create("Toybox Engine", new Math::Size(1920, 1080));
    }

    Application::~Application()
    {
        if (_isOpen) Close();
        delete _window;
    }
    
    void Application::Launch()
    {
        _isOpen = true;
        OnOpen();
        while (_isOpen) 
        {
            Update();
            _window->Update();
        }
    }

    void Application::Close()
    {
        _isOpen = false;
    }

    std::string Application::GetName()
    {
        return _name;
    }
}
