#pragma once
#include "IWindow.h"
#include "Debug/Logging/Logging.h"
#include "Math/Size.h"

namespace Toybox::Modules
{
    class TOYBOX_API WindowFactory
    {
    public:
        static IWindow* Create(const std::string& title, Toybox::Math::Size* size);
    };
}
