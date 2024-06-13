#include "tbxpch.h"
#include "GlfwWindow.h"
#include "Debug/Logging/Logging.h"
#include "Debug/Assert.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

static bool s_glfwInitialized = false;
GLFWwindow* _glfwWindow;

Toybox::Modules::GlfwWindow::GlfwWindow(const std::string title, Math::Size* size)
{
    _title = title;
    _size = size;
    _vSyncEnabled = true;

    TBX_INFO(std::format("Creating a new glfw window: {} of size: {}, {}", title, size->Width, size->Height));

    if (!s_glfwInitialized)
    {
        const bool success = glfwInit();
        s_glfwInitialized = true;
        TBX_ASSERT(success, "Failed to initialize glfw!");
    }

    _glfwWindow = glfwCreateWindow(_size->Width, _size->Height, _title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(_glfwWindow);
    glfwSetWindowUserPointer(_glfwWindow, this);

    SetVSyncEnabled(_vSyncEnabled);
}

Toybox::Modules::GlfwWindow::~GlfwWindow()
{
    glfwDestroyWindow(_glfwWindow);
    delete _size;
}

void Toybox::Modules::GlfwWindow::Update()
{
    glfwPollEvents();
    glfwSwapBuffers(_glfwWindow);
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

