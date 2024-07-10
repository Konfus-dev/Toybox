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
        _mainWindow = new GlfwWindow(name, new Math::Size(1920, 1080), WindowMode::Borderless);
        _mainWindow->SetEventCallback(TBX_BIND_EVENT_FN(App::OnEvent));
    }

    App::~App()
    {
        if (_isRunning) Close();
        delete _mainWindow;
    }
    
    void App::Launch()
    {
        _isRunning = true;
        OnOpen();
    }

    void App::Update()
    {
        _mainWindow->Update();
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
