int main() {
    int n = 1L; // expression 1L has type long, int is expected
    n = 2.1; // expression 2.1 has type double, int is expected
    char *p = malloc(10); // expression malloc(10) has type void*, char* is expected
}