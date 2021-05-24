void f(int);

void func(int x) {
    printf("func(%d): ", x);
    switch(x) {
        case 1: printf("case 1, ");
        case 2: printf("case 2, ");
        case 3: printf("case 3.\n"); break;
        case 4: printf("case 4, ");
        case 5: printf("case 5, ");
        default: printf("default.\n");
    }
}

int main() {
    switch(1) {
        case 1: puts("1"); // prints "1"
        case 2: puts("2"); // then prints "2" ("fall-through")
    }

    switch(1) {
        case 1: puts("1"); // prints "1"
                break;     // and exits the switch
        case 2: puts("2");
                break;
    }

    switch(0) {
        int i = 4;
        f(i); // never called
        // int a[i]; // error: VLA cannot be declared here

        case 0:
            i = 17;
        default:
            int a[i]; // OK to declare VLA here
            printf("%d\n", i); // prints 17 if expr == 0, prints indeterminate value otherwise
    }
    // VLA must be declared either before the entire switch
    // or after the last label

    for(int i = 1; i < 9; ++i) func(i);
}