#pragma once
#include "../../API/ToyboxAPI.h"

namespace Toybox::Modules
{
    class TOYBOX_API ILogger
    {
    public:
        virtual ~ILogger() = default;
        virtual void Log(int lvl, std::string msg) = 0;
    };
}