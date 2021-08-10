export module math;

template<typename T1, typename T2>
concept Add = requires (T1 a, T2 b) {
	a + b;
};

export namespace math {
	template <typename T1, typename T2> requires Add<T1, T2>
	auto sum(T1 a, T2 b) {
		return a + b;
	}
}
