// Expressions that are used in the initializers of objects with static and
// thread_local storage duration must be expressions that may be one of the
// following:

// * arithmetic constant expression
// * the null pointer constant NULL
// * address constant expression, which is
//	* a null pointer
//	* lvalue designating an object of static storage duration or a function
//	  designator, converted to a pointer either
//		* by causing the unary address-of operator
//		* by casting an integer constant to a pointer
//		* by array-to-pointer or function-to-pointer implicit conversion
// * address constant expression of some complete object type, plus or minus an
//   integer constant expression

int main() {
	// Static init exprs are not required to be evaluated at compile time

	static int i = 2 || 1 / 0; // 1
}
