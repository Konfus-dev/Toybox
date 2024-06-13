#pragma once
#include "Log.h"
#include "LogLevel.h"
#include <format>

#define TBX_TRACE(msg)         ::Toybox::Debug::Log::Trace(msg)
#define TBX_INFO(msg)          ::Toybox::Debug::Log::Info(msg)
#define TBX_WARN(msg)          ::Toybox::Debug::Log::Warn(msg)
#define TBX_ERROR(msg)         ::Toybox::Debug::Log::Error(msg)
#define TBX_CRITICAL(msg)      ::Toybox::Debug::Log::Critical(msg)
