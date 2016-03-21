#pragma once

#include <type_traits>

class BSFixedString;
template <class> class VMArray;

namespace BSScript {
	struct StaticFunctionTag;

	struct typeid_None : std::integral_constant<VMTypeID, 0U>{};
	struct typeid_String : std::integral_constant<VMTypeID, 2U>{};
	struct typeid_Int : std::integral_constant<VMTypeID, 3U>{};
	struct typeid_Float : std::integral_constant<VMTypeID, 4U>{};
	struct typeid_Bool : std::integral_constant<VMTypeID, 5U>{};

	template<class>	struct typeid_builtin{};
	template<> struct typeid_builtin<void> : typeid_None{};
	template<> struct typeid_builtin<SInt32> : typeid_Int{};
	template<> struct typeid_builtin<UInt32> : typeid_Int{};
	template<> struct typeid_builtin<float> : typeid_Float{};
	template<> struct typeid_builtin<bool> : typeid_Bool{};
	template<> struct typeid_builtin<const char *> : typeid_String{};
	template<> struct typeid_builtin<BSFixedString> : typeid_String{};
	template<> struct typeid_builtin<const BSFixedString &> : typeid_String{};

	/// is_static
	template <class _Ty>
	struct is_static : std::is_same < _Ty, StaticFunctionTag > {};

	template <class _Ty>
	struct is_static_pointer : std::conditional < std::is_pointer<_Ty>::value, is_static<typename std::remove_pointer<_Ty>::type>, std::false_type > ::type
	{};

	/// is_builtin
	template <class> struct is_builtin : std::false_type {};
	template<> struct is_builtin<void> : std::true_type{};
	template<> struct is_builtin<SInt32> : std::true_type{};
	template<> struct is_builtin<UInt32> : std::true_type{};
	template<> struct is_builtin<float> : std::true_type{};
	template<> struct is_builtin<bool> : std::true_type{};
	template<> struct is_builtin<const char *> : std::true_type{};
	template<> struct is_builtin<BSFixedString> : std::true_type{};
	template<> struct is_builtin<const BSFixedString &> : std::true_type{};

	/// is_form
	template <class _Ty>
	struct is_form
	{
	private:
		template <class, int>
		struct check_if_form_helper{};

		template <class T>
		static std::true_type check_if_form(check_if_form_helper<T, T::kTypeID> * p);

		template <class T>
		static std::false_type check_if_form(...);

	public:
		static const bool value = decltype(check_if_form<_Ty>(nullptr))::value;
	};
	template <>
	struct is_form<StaticFunctionTag> : std::false_type{};

	/// is_form_pointer
	template <class _Ty>
	struct is_form_pointer : std::conditional < std::is_pointer<_Ty>::value, is_form<typename std::remove_pointer<_Ty>::type>, std::false_type > ::type
	{};

	/// is_array
	template <class>
	struct is_array : std::false_type {};

	template <class _Ty>
	struct is_array<VMArray<_Ty>> : std::true_type{};

	/// remove_array
	template <class _Ty>
	struct remove_array
	{
		typedef _Ty type;
	};

	template <class _Ty>
	struct remove_array < VMArray<_Ty> >
	{
		typedef _Ty type;
	};

	/// is_packable
	template <class _Ty>
	struct is_packable : std::integral_constant < bool,
		!std::is_same<_Ty, StaticFunctionTag *>::value && !std::is_void<_Ty>::value && (
			is_builtin<_Ty>::value || is_form_pointer<_Ty>::value || (
				is_array<_Ty>::value && (
					is_builtin<typename remove_array<_Ty>::type>::value ||
					is_form_pointer<typename remove_array<_Ty>::type>::value
					)
				)
			) >
	{};

	/// is_valid_result
	template <class _Ty>
	struct is_valid_result : std::integral_constant < bool, std::is_void<_Ty>::value || is_packable<_Ty>::value >
	{};

	/// is_valid_base
	template <class _Ty>
	using is_valid_base = is_form<_Ty>;

	/// are_packable
	template <class...>
	struct are_packable;

	template <class T0, class... Ty>
	struct are_packable<T0, Ty...> : std::integral_constant< bool, is_packable<T0>::value && are_packable<Ty...>::value >
	{};

	template <class T0>
	struct are_packable<T0> : public is_packable<T0>
	{};

	template <>
	struct are_packable<> : public std::true_type
	{};
}
