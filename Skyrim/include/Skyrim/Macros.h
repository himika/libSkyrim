#pragma once

#define __MACRO_JOIN__(a, b)		__MACRO_JOIN_2__(a, b)
#define __MACRO_JOIN_2__(a, b)		__MACRO_JOIN_3__(a, b)
#define __MACRO_JOIN_3__(a, b)		a##b

#if defined(_MSC_VER)
#  define FORCE_INLINE __forceinline
#elif defined(__GNUC__)
#  define FORCE_INLINE __attribute__((always_inline))
#else
#  define FORCE_INLINE inline
#endif

#define DEFINE_MEMBER_FN(fnName, retnType, addr, ...)							\
	template <class... Params>													\
	FORCE_INLINE retnType fnName(Params&&... params) {							\
		struct empty_struct {};													\
		typedef retnType(empty_struct::*_##fnName##_type)(__VA_ARGS__);			\
		const static UInt32 address = addr;										\
		_##fnName##_type fn = *(_##fnName##_type*)&address;						\
		return (reinterpret_cast<empty_struct*>(this)->*fn)(params...);			\
	}

#define DEFINE_MEMBER_FN_const(fnName, retnType, addr, ...)						\
	template <class... Params>													\
	FORCE_INLINE retnType fnName(Params&&... params) const {					\
		struct empty_struct {};													\
		typedef retnType(empty_struct::*_##fnName##_type)(__VA_ARGS__) const;	\
		const static UInt32 address = addr;										\
		_##fnName##_type fn = *(_##fnName##_type*)&address;						\
		return (reinterpret_cast<const empty_struct*>(this)->*fn)(params...);	\
	}

#define DEFINE_STATIC_FN(fnName, retnType, addr, ...)		\
	template <class... Params>								\
	FORCE_INLINE static retnType fnName(Params&&... params) {		\
		typedef retnType(*Fn)(__VA_ARGS__);					\
		const Fn fn = (Fn)(addr);							\
		return fn(params...);								\
	}

#ifdef _DEBUG
#  define STATIC_ASSERT(a) static_assert((a), "static assert failure: " #a)
#else
#  define STATIC_ASSERT(a)
#endif

#define CLASS_SIZE_ASSERT(size)									\
	FORCE_INLINE void _size_assert_ ## __COUNTER__() const {	\
		static_assert(sizeof(*this) == size, "wrong size");		\
	}


#if _MSC_VER >= 1900
#  define DEPRECATED_TYPEDEF(type_name, deprecated_name)	[[deprecated("use " #type_name " instead")]] typedef type_name deprecated_name
#  define DEPRECATED__(message)	[[deprecated(message)]]
#else
#  define DEPRECATED_TYPEDEF(type_name, deprecated_name)	typedef __declspec(deprecated("use " #type_name " instead")) type_name deprecated_name
#  define DEPRECATED__(message)	[[deprecated(message)]]
#endif
