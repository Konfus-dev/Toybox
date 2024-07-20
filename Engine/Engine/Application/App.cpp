#include "tbxpch.h"
#include "App.h"
#include "IWindow.h"
#include "GlfwWindow.h"

namespace Toybox::Application
{
    bool _isRunning;
    std::string _name;
    IWindow* _mainWindow;

    App::App(const std::string& name)
    {
        _name = name;
        _isRunning = false;
    }

    App::~App()
    {
        if (_isRunning) Close();
        delete _mainWindow;
    }
    
    void App::Launch()
    {
        _isRunning = true;
        _mainWindow = new GlfwWindow(_name, new Math::Size(1920, 1080), WindowMode::Windowed);
        _mainWindow->SetEventCallback(TBX_BIND_EVENT_FN(App::OnEvent));
        OnOpen();
    }

    void App::Update()
    {
        _mainWindow->Update();

        Events::AppUpdateEvent updateEvent;
        OnEvent(updateEvent);

        OnUpdate();
    }

    void App::Close()
    {
        _isRunning = false;
    }

    const bool App::IsRunning()
    {
        return _isRunning;
    }

    const std::string& App::GetName()
    {
        return _name;
    }

    const IWindow* App::GetMainWindow()
    {
        return _mainWindow;
    }

    bool App::OnWindowClose(Events::WindowCloseEvent& e)
    {
        Close();
        return true;
    }

    void App::OnEvent(Events::Event& e)
    {
        Events::EventDispatcher dispatcher(e);
        dispatcher.Dispatch<Events::WindowCloseEvent>(TBX_BIND_EVENT_FN(App::OnWindowClose));
        //dispatcher.Dispatch<WindowResizeEvent>(TBX_BIND_EVENT_FN(Application::OnWindowResize));

        /*for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
        {
            if (e.Handled)
                break;
            (*it)->OnEvent(e);
        }*/
    }
}
