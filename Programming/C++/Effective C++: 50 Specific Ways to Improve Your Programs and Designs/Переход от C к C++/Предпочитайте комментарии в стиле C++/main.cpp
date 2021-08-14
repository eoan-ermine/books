void bad(int a, int b) {
	if (a > b) {
		/*
		int temp = a; /* поменять a и b */
		a = b;
		b = temp;
		*/
	}
}

void good() {
	if (a > b) {
		// int temp = a; // Поменять a и b
		// a = b;
		// b = temp;
	}
}

int main() { }
