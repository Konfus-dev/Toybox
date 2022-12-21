#pragma once
#include "LogLevel.h"
#include "API/ToyboxAPI.h"
#include "Modules/Logger/LoggerFactory.h"

namespace Toybox::Debug
{
    class TOYBOX_API Log
    {
    public:
        static void Trace(std::string msg)
        {
            _logger->Log(LogLevel::Trace, msg);
        }

        static void Info(std::string msg)
        {
            _logger->Log(LogLevel::Info, msg);
        }

        static void Warn(std::string msg)
        {
            _logger->Log(LogLevel::Warn, msg);
        }

        static void Error(std::string msg)
        {
            _logger->Log(LogLevel::Error, msg);
        }

        static void Critical(std::string msg)
        {
            _logger->Log(LogLevel::Critical, msg);
        }

    private:
        static inline Modules::ILogger* _logger = Modules::LoggerFactory::Create();
    };
}
