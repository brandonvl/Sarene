#pragma once

#ifdef SAR_ENABLE_ASSERTS
#define SAR_ASSERT(x, ...) { if(!(x)) { SAR_LOG_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SAR_ASSERT(x, ...)
#endif

template<typename T>
constexpr auto BIT(T x)
{
	return (1 << x);
}