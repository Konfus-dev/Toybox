#include "tbxpch.h"
#include "GlfwWindowsWindow.h"
#include "Debug/Logging/Logging.h"
#include "Debug/Assert.h"

static bool s_glfwInitialized = false;

Toybox::Modules::GlfwWindowsWindow::GlfwWindowsWindow(const std::string title, Math::Size* size)
{
    _title = title;
    _size = size;
    _vSyncEnabled = true;

    TBX_INFO(fmt::format("Creating a new glfw window: {} of size: {}, {}", title, size->Width, size->Height));

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

Toybox::Modules::GlfwWindowsWindow::~GlfwWindowsWindow()
{
    glfwDestroyWindow(_glfwWindow);
    delete _size;
}

void Toybox::Modules::GlfwWindowsWindow::Update()
{
    glfwPollEvents();
    glfwSwapBuffers(_glfwWindow);
}

void Toybox::Modules::GlfwWindowsWindow::SetVSyncEnabled(const bool enabled)
{
    _vSyncEnabled = enabled;
    glfwSwapInterval(_vSyncEnabled);
}

bool Toybox::Modules::GlfwWindowsWindow::GetVSyncEnabled() const
{
    return _vSyncEnabled;
}

Toybox::Math::Size* Toybox::Modules::GlfwWindowsWindow::GetSize() const
{
    return _size;
}

std::string Toybox::Modules::GlfwWindowsWindow::GetTitle() const
{
    return _title;
}

