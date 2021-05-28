int main(void) {
	// Arithhmetic constants of floating-point types that are not used
	// in static initializers are always evaluated as-if during run-time

	#pragma STDC FENV_ACCESS ON
	static float x = 0.0/0.0; // static initializer: does not raise an exception
	float w[] = { 0.0 / 0.0 }; // raises an exception
	float y = 0.0 / 0.0; // raises an exception
	double z = 0.0 / 0.0; // raises an exception
}
