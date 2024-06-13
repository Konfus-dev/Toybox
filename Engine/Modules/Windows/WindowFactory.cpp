#include "tbxpch.h"
#include "WindowFactory.h"
#include "GlfwWindow.h"
#include "Debug/Assert.h"

namespace Toybox::Modules
{
    IWindow* WindowFactory::Create(std::string title, Toybox::Math::Size* size)
    {
        #ifdef TBX_PLATFORM_WINDOWS
            return new GlfwWindow(title, size);
        #else
            TBX_ASSERT(false, "Unknown platform!");
            return nullptr;
        #endif
    }
}
