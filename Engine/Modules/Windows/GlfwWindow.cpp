#include "tbxpch.h"
#include "GlfwWindow.h"
#include "Debug/Logging/Logging.h"
#include "Debug/Assert.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

static bool s_glfwInitialized = false;
GLFWwindow* _glfwWindow;

Toybox::Modules::GlfwWindow::GlfwWindow(const std::string& title, Math::Size* size)
{
    _title = title;
    _size = size;
    _vSyncEnabled = true;

    TBX_INFO("Creating a new glfw window...");

    if (!s_glfwInitialized)
    {
        const bool success = glfwInit();
        s_glfwInitialized = true;
        TBX_ASSERT(success, "Failed to initialize glfw!");
    }

    // TODO: Add a way to change window type:
    /* Windowed mode (monitor = nullptr)
     * Fullscreen mode (monitor != nullptr)
     * Windowed borderless (monitor = nullptr, decorated = false)
     * Fullscreen borderless (monitor != nullptr, video mode = monitor mode) */
    //glfwWindowHint(GLFW_DECORATED, false);
    _glfwWindow = glfwCreateWindow(_size->Width, _size->Height, _title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_glfwWindow);
    glfwSetWindowUserPointer(_glfwWindow, this);
    //SetVSyncEnabled(_vSyncEnabled);
    
    TBX_INFO(std::format("Created a new glfw window: {} of size: {}, {}", title, size->Width, size->Height));
}

Toybox::Modules::GlfwWindow::~GlfwWindow()
{
    glfwDestroyWindow(_glfwWindow);
    delete _size;
}

float _red = 1;
float _green = 0.5f;
float _blue = 0;

void Toybox::Modules::GlfwWindow::Update()
{
    TBX_INFO("Updating window: " + _title);
    
    glfwPollEvents();
    glfwSwapBuffers(_glfwWindow);

    // TESTING CODE!
    {
        glClearColor(_red, _green, _blue, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        if (_red > 1)
            _red = 0;
        if (_red < 0)
            _red = 1;

        if (_green > 1)
            _green = 0;
        if (_green < 0)
            _green = 1;

        if (_blue > 1)
            _blue = 0;
        if (_blue < 0)
            _blue = 1;

        _red += 0.01f;
        _green += 0.01f;
        _blue += 0.01f;
    }
}

void Toybox::Modules::GlfwWindow::SetVSyncEnabled(const bool enabled)
{
    _vSyncEnabled = enabled;
    glfwSwapInterval(_vSyncEnabled);
}

bool Toybox::Modules::GlfwWindow::GetVSyncEnabled() const
{
    return _vSyncEnabled;
}

int Toybox::Modules::GlfwWindow::GetHandle() const
{
    return (int)glfwGetWin32Window(_glfwWindow);
}

Toybox::Math::Size* Toybox::Modules::GlfwWindow::GetSize() const
{
    return _size;
}

std::string Toybox::Modules::GlfwWindow::GetTitle() const
{
    return _title;
}

