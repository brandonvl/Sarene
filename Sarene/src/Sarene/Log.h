#pragma once

// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace Sarene
{
	class Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger> &GetLogger()
		{
			return s_Logger;
		};
	private:
		static std::shared_ptr<spdlog::logger> s_Logger;
	};
}

#define SAR_LOG_TRACE(...)		::Sarene::Log::GetLogger()->trace(__VA_ARGS__)
#define SAR_LOG_INFO(...)		::Sarene::Log::GetLogger()->info(__VA_ARGS__)
#define SAR_LOG_WARN(...)		::Sarene::Log::GetLogger()->warn(__VA_ARGS__)
#define SAR_LOG_ERROR(...)		::Sarene::Log::GetLogger()->error(__VA_ARGS__)
#define SAR_LOG_FATAL(...)		::Sarene::Log::GetLogger()->critical(__VA_ARGS__)