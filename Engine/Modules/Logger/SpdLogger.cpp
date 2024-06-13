#include "tbxpch.h"
#include "SpdLogger.h"
#include <spdlog/spdlog.h>
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Toybox::Modules
{
    std::shared_ptr<spdlog::logger> _spdLogger;

    SpdLogger::SpdLogger()
    {
        _spdLogger = spdlog::stdout_color_mt("LOGGER");
        _spdLogger->set_pattern("%^[%T]: %v%$");
        _spdLogger->set_level(spdlog::level::level_enum::trace);
    }

    SpdLogger::SpdLogger(std::string name)
    {
        _spdLogger = spdlog::stdout_color_mt(name);
        _spdLogger->set_pattern("%^[%T]: %v%$");
        _spdLogger->set_level(spdlog::level::level_enum::trace);
    }

    SpdLogger::~SpdLogger()
    {
        _spdLogger->flush();
        spdlog::drop(_spdLogger->name());
    }

    void SpdLogger::Log(int lvl, std::string msg)
    {
        _spdLogger->log(spdlog::source_loc{}, (spdlog::level::level_enum)lvl, msg);
    }
}
