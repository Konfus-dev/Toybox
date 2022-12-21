#pragma once
#include "ILogger.h"
#include "SpdLogger.h"

namespace Toybox::Modules
{
    class TOYBOX_API LoggerFactory
    {
    public:
        static ILogger* Create()
        {
            return new SpdLogger();
        }

        static ILogger* Create(std::string name)
        {
            return new SpdLogger(name);
        }
    };
}
