#include <type_traits>
#include <concepts>
#include <numeric>

template<typename T>
struct isSemiRegular: std::bool_constant<
	std::is_default_constructible_v<T> &&
	std::is_copy_constructible_v<T> &&
	std::is_copy_assignable_v<T> &&
	std::is_move_constructible_v<T> &&
	std::is_move_assignable_v<T> &&
	std::is_destructible_v<T> &&
	std::is_swappable_v<T>
> { };

template<typename T>
concept SemiRegular = isSemiRegular<T>::value;
