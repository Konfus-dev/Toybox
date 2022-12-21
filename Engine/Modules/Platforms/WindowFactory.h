#pragma once
#include "IWindow.h"
#include "Debug/Assert.h"
#include "Debug/Logging/Logging.h"
#include "Math/Size.h"
#include "Windows/GlfwWindowsWindow.h"

namespace Toybox::Modules
{
    class TOYBOX_API WindowFactory
    {
    public:
        static IWindow* Create(std::string title, Toybox::Math::Size* size)
        {
            #ifdef TBX_PLATFORM_WINDOWS
                return new GlfwWindowsWindow(title, size);
            #else
                TBX_ASSERT(false, "Unknown platform!");
                return nullptr;
            #endif
        }
    };
}
