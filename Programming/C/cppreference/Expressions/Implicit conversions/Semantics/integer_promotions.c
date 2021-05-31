void f(int x) {}

int main(void) {
    // If int can represent the entire range of values of the
    // original type, the value is converted to type int
    // Otherwise the value is converted to unsigned int

    char x = 'a'; // integer conversion from int to char
    f(x); // integer promotion from char back to int
}