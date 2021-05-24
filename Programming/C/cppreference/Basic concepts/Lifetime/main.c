int* foo(void) {
    int a = 17; // a has automatic storage duration
    return &a;
}

int main(void) {
    int* p = foo(); // p points to an object past lifetime ("dangling pointer")
    int n = *p; // undefined behavior
}