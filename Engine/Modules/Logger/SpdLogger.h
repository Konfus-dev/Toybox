#pragma once
#include "ILogger.h"
#include "../../API/ToyboxAPI.h"

namespace Toybox::Modules
{
    class TOYBOX_API SpdLogger : public ILogger
    {
    public:
        SpdLogger();
        SpdLogger(std::string name);
        ~SpdLogger() override;
        void Log(int lvl, std::string msg) override;
    };
}

