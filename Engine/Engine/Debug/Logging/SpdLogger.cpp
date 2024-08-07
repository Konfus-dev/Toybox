#pragma once

#include "tbxpch.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "SpdLogger.h"

std::shared_ptr<spdlog::logger> _spdLogger;

Toybox::Debug::SpdLogger::SpdLogger()
{
    _spdLogger = spdlog::stdout_color_mt("CORE");
    _spdLogger->set_pattern("%^[%T]: %v%$");
    _spdLogger->set_level(spdlog::level::level_enum::trace);
}

Toybox::Debug::SpdLogger::SpdLogger(std::string name)
{
    _spdLogger = spdlog::stdout_color_mt(name);
    _spdLogger->set_pattern("%^[%T]: %v%$");
    _spdLogger->set_level(spdlog::level::level_enum::trace);
}

Toybox::Debug::SpdLogger::~SpdLogger()
{
    _spdLogger->flush();
    spdlog::drop(_spdLogger->name());
}

void Toybox::Debug::SpdLogger::Log(int lvl, std::string msg)
{
    _spdLogger->log(spdlog::source_loc{}, (spdlog::level::level_enum)lvl, msg);
}
