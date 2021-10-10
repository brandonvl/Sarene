#pragma once

#include "Core.h"
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

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return s_CoreLogger;
		}
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return s_ClientLogger;
		}
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define SAR_CORE_TRACE(...)		::Sarene::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SAR_CORE_INFO(...)		::Sarene::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SAR_CORE_WARN(...)		::Sarene::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SAR_CORE_ERROR(...)		::Sarene::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SAR_CORE_CRITICAL(...)	::Sarene::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define SAR_TRACE(...)			::Sarene::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SAR_INFO(...)			::Sarene::Log::GetClientLogger()->info(__VA_ARGS__)
#define SAR_WARN(...)			::Sarene::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SAR_ERROR(...)			::Sarene::Log::GetClientLogger()->error(__VA_ARGS__)
#define SAR_CRITICAL(...)		::Sarene::Log::GetClientLogger()->critical(__VA_ARGS__)