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
		_logger->Log(LogLevel::Info, msg);
	}

	void Log::Warn(std::string msg)
	{
		_logger->Log(LogLevel::Warn, msg);
	}

	void Log::Error(std::string msg)
	{
		_logger->Log(LogLevel::Error, msg);
	}

	void Log::Critical(std::string msg)
	{
		_logger->Log(LogLevel::Critical, msg);
	}

	template<typename... Args>
	void Log::Trace(std::string msg, Args&&... args)
	{
		va_start(args, msg);
		_logger->Log(LogLevel::Trace, std::format(msg, args));
		va_end(args);
	}

	template<typename... Args>
	void Log::Info(std::string msg, Args&&... args)
	{
		va_start(args, msg);
		_logger->Log(LogLevel::Info, std::format(msg, args));
		va_end(args);
	}

	template<typename... Args>
	void Log::Warn(std::string msg, Args&&... args)
	{
		va_start(args, msg);
		_logger->Log(LogLevel::Warn, std::format(msg, args));
		va_end(args);
	}

	template<typename... Args>
	void Log::Error(std::string msg, Args&&... args)
	{
		va_start(args, msg);
		_logger->Log(LogLevel::Error, std::format(msg, args));
		va_end(args);
	}

	template<typename... Args>
	void Log::Critical(std::string msg, Args&&... args)
	{
		va_start(args, msg);
		_logger->Log(LogLevel::Critical, std::format(msg, args));
		va_end(args);
	}
}