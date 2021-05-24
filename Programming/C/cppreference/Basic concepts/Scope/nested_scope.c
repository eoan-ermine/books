// Nested scope

int a;

void f(void) {
    int a = 1;
    {
        int a = 2;
        printf("%d\n", a); // 2
    }
    printf("%d\n", a);
}

void g(int a); // hides file-scope a