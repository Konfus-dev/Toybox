#pragma once

#include "ToyboxAPI.h"
#include "LogLevel.h"

namespace Toybox::Debug
{
    class TOYBOX_API Log
    {
    public:
        static void Trace(std::string msg);

        static void Info(std::string msg);

        static void Warn(std::string msg);

        static void Error(std::string msg);

        static void Critical(std::string msg);
    };
}
