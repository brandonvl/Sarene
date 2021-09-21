#pragma once


#ifdef SAR_DEBUG
	#define SAR_ENABLE_ASSERTS
#endif

#ifdef SAR_ENABLE_ASSERTS
#define SAR_CORE_ASSERT(x, ...) { if(!(x)) { SAR_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define SAR_ASSERT(x, ...) { if(!(x)) { SAR_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define SAR_CORE_ASSERT(x, ...)
#define SAR_ASSERT(x, ...)
#endif

template<typename T>
constexpr auto BIT(T x)
{
	return (1 << x);
}

#define SAR_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)