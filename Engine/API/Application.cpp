#include "tbxpch.h"
#include "Application.h"

#include <thread>

#include "Modules/Windows/WindowFactory.h"

namespace Toybox
{
    bool _isRunning;
    std::string _name;
    Modules::IWindow* _mainWindow;

    Application::Application(const std::string& name)
    {
        _name = name;
        _isRunning = false;
        _mainWindow = Modules::WindowFactory::Create(name, new Math::Size(1920, 1080));
    }

    Application::~Application()
    {
        if (_isRunning) Close();
        delete _mainWindow;
    }
    
    void Application::Launch()
    {
        _isRunning = true;
        OnOpen();
    }

    void Application::Update()
    {
        _mainWindow->Update();
        OnUpdate();
    }

    void Application::Close()
    {
        _isRunning = false;
    }

    int Application::GetHandle()
    {
        return _mainWindow->GetHandle();
    }

    bool Application::GetIsRunning()
    {
        return _isRunning;
    }

    Modules::IWindow* Application::GetMainWindow()
    {
        return _mainWindow;
    }
}
