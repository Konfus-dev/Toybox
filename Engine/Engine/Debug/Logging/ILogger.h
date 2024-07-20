#pragma once

#include "ToyboxAPI.h"

namespace Toybox::Debug
{
    class ILogger
    {
    public:
        virtual ~ILogger() = default;
        virtual void Log(int lvl, std::string msg) = 0;
    };
}