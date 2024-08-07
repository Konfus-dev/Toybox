#include "tbxpch.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
#include "GlfwWindow.h"
#include "WindowMode.h"
#include "Debug/Logging/Logging.h"
#include "Debug/Assert.h"
#include "Events/Events.h"

namespace Toybox::Application
{
	static bool s_glfwInitialized = false;
	GLFWwindow* _glfwWindow;

	GlfwWindow::GlfwWindow(const std::string& title, Math::Size* size, WindowMode mode)
	{
		_title = title;
		_size = size;
		_vSyncEnabled = true;

		TBX_INFO("Creating a new glfw window...");

		if (!s_glfwInitialized)
		{
			const bool success = glfwInit();
			TBX_ASSERT(success, "Failed to initialize glfw!");
			s_glfwInitialized = true;
		}

		SetMode(mode);
    
		TBX_INFO("Created a new glfw window: {} of size: {}, {}", title, size->Width, size->Height);
	}

	GlfwWindow::~GlfwWindow()
	{
		glfwDestroyWindow(_glfwWindow);
		delete _size;
	}

	void GlfwWindow::Update()
	{
		TBX_INFO("Updating window: " + _title);

		glfwPollEvents();
		glfwSwapBuffers(_glfwWindow);
	}

	void GlfwWindow::SetVSyncEnabled(const bool enabled)
	{
		_vSyncEnabled = enabled;
		glfwSwapInterval(_vSyncEnabled);
	}

	bool GlfwWindow::GetVSyncEnabled() const
	{
		return _vSyncEnabled;
	}

	void GlfwWindow::SetSize(Math::Size* size)
	{
		_size = size;
	}

	Math::Size* GlfwWindow::GetSize() const
	{
		return _size;
	}

	std::string GlfwWindow::GetTitle() const
	{
		return _title;
	}

	Math::uint64 GlfwWindow::GetId() const
	{
		// TODO: make this platform agnostic (need to do diff things depending on platform!)
		return (Math::uint64)glfwGetWin32Window(_glfwWindow);
	}

	void GlfwWindow::SetEventCallback(const EventCallbackFn& callback)
	{
		_eventCallback = callback;
	}

	void GlfwWindow::SetMode(WindowMode mode)
	{
		if (_glfwWindow != nullptr)
		{
			glfwDestroyWindow(_glfwWindow);
		}

		switch (mode)
		{
			//Windowed mode (monitor = nullptr)
			case WindowMode::Windowed:
			{
				_glfwWindow = glfwCreateWindow((int)_size->Width, (int)_size->Height, _title.c_str(), nullptr, nullptr);
				break;
			}
			// Fullscreen mode (monitor != nullptr)
			case WindowMode::Fullscreen:
			{
				_glfwWindow = glfwCreateWindow((int)_size->Width, (int)_size->Height, _title.c_str(), glfwGetPrimaryMonitor(), nullptr);
				break;
			}
			// Borderless (monitor = nullptr, decorated = false)
			case WindowMode::Borderless:
			{
				glfwWindowHint(GLFW_DECORATED, false);
				_glfwWindow = glfwCreateWindow((int)_size->Width, (int)_size->Height, _title.c_str(), nullptr, nullptr);
				break;
			}
			// Fullscreen borderless (monitor != nullptr, video mode = monitor mode)
			case WindowMode::FullscreenBorderless:
			{
				_glfwWindow = glfwCreateWindow((int)_size->Width, (int)_size->Height, _title.c_str(), glfwGetPrimaryMonitor(), nullptr);
				break;
			}
		}

		SetVSyncEnabled(_vSyncEnabled);
		SetupContext();
		SetupCallbacks();
	}

	void GlfwWindow::SetupCallbacks()
	{
		// Setup callbacks
		glfwSetWindowSizeCallback(_glfwWindow, [](GLFWwindow* window, int width, int height)
		{
			GlfwWindow& toyboxWindow = *(GlfwWindow*)glfwGetWindowUserPointer(window);
			toyboxWindow.SetSize(new Math::Size(width, height));

			Events::WindowResizeEvent event(width, height);
			toyboxWindow._eventCallback(event);
		});

		glfwSetWindowCloseCallback(_glfwWindow, [](GLFWwindow* window)
		{
			GlfwWindow& toyboxWindow = *(GlfwWindow*)glfwGetWindowUserPointer(window);
			Events::WindowCloseEvent event;
			toyboxWindow._eventCallback(event);
		});

		glfwSetKeyCallback(_glfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			GlfwWindow& toyboxWindow = *(GlfwWindow*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				Events::KeyPressedEvent event(key);
				toyboxWindow._eventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				Events::KeyReleasedEvent event(key);
				toyboxWindow._eventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				Events::KeyRepeatedEvent event(key, 1);
				toyboxWindow._eventCallback(event);
				break;
			}
			}
		});

		glfwSetCharCallback(_glfwWindow, [](GLFWwindow* window, unsigned int keycode)
		{
			GlfwWindow& toyboxWindow = *(GlfwWindow*)glfwGetWindowUserPointer(window);

			Events::KeyPressedEvent event(keycode);
			toyboxWindow._eventCallback(event);
		});

		glfwSetMouseButtonCallback(_glfwWindow, [](GLFWwindow* window, int button, int action, int mods)
		{
			GlfwWindow& toyboxWindow = *(GlfwWindow*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				Events::MouseButtonPressedEvent event(button);
				toyboxWindow._eventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				Events::MouseButtonReleasedEvent event(button);
				toyboxWindow._eventCallback(event);
				break;
			}
			}
		});

		glfwSetScrollCallback(_glfwWindow, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			GlfwWindow& toyboxWindow = *(GlfwWindow*)glfwGetWindowUserPointer(window);

			Events::MouseScrolledEvent event((float)xOffset, (float)yOffset);
			toyboxWindow._eventCallback(event);
		});

		glfwSetCursorPosCallback(_glfwWindow, [](GLFWwindow* window, double xPos, double yPos)
		{
			GlfwWindow& toyboxWindow = *(GlfwWindow*)glfwGetWindowUserPointer(window);

			Events::MouseMovedEvent event((float)xPos, (float)yPos);
			toyboxWindow._eventCallback(event);
		});
	}

	void GlfwWindow::SetupContext()
	{
		glfwMakeContextCurrent(_glfwWindow);
		glfwSetWindowUserPointer(_glfwWindow, this);
	}
}