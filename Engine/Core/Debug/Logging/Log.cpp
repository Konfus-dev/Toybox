#include "tbxpch.h"
#include "Log.h"
#include "ILogger.h"
#include "SpdLogger.h"

namespace Toybox::Debug
{
	ILogger* _logger = new SpdLogger();

	void Log::Trace(std::string msg)
	{
		_logger->Log(LogLevel::Trace, msg);
	}

	void Log::Info(std::string msg)
	{
		_logger->Log(LogLevel::Trace, msg);
	}

	void Log::Warn(std::string msg)
	{
		_logger->Log(LogLevel::Trace, msg);
	}

	void Log::Error(std::string msg)
	{
		_logger->Log(LogLevel::Trace, msg);
	}

	void Log::Critical(std::string msg)
	{
		_logger->Log(LogLevel::Trace, msg);
	}
}