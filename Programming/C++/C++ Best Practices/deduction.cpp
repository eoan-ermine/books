#include <type_traits>

const int* get_p() {
	return 0;
}

const int& get_r() {
	return 0;
}

int main() {
	const auto val_0 = get_p();
	static_assert(
		std::is_same_v<decltype(val_0), const int* const>
	);

	const auto val_1 = get_r();
	static_assert(
		std::is_same_v<decltype(val_1), const int>
	);

	const auto* val_2 = get_p();
	static_assert(
		std::is_same_v<decltype(val_2), const int*>
	);

	const auto& val_3 = get_r();
	static_assert(
		std::is_same_v<decltype(val_3), const int&>
	);

	const auto& val_4 = get_p();
	static_assert(
		std::is_same_v<decltype(val_4), const int* const&>
	);

//	const auto&& val_5 = get_r();
//	static_assert(
//		std::is_same_v<decltype(val_5), const int&>
//	);
}
