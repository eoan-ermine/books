int n; // declaration of an int
sizeof(int); // use of type name
 
int *a[3]; // declaration of an array of 3 pointers to int
sizeof(int *[3]); // use of type name
 
int (*p)[3]; // declaration of a pointer to array of 3 int
sizeof(int (*)[3]); // use of type name
 
int (*a)[*] // declaration of pointer to VLA (in a function parameter)
sizeof(int (*)[*]) // use of type name (in a function parameter)
 
int *f(void); // declaration of function
sizeof(int *(void)); // use of type name
 
int (*p)(void); // declaration of pointer to function
sizeof(int (*)(void)); // use of type name
 
int (*const a[])(unsigned int, ...) = {0}; // array of pointers to functions
sizeof(int (*const [])(unsigned int, ...)); // use of type name

int (n); // declares n of type int
sizeof(int ()); // uses type "function returning int"

// Type name may introduce a new type:

void* p = (void*)(struct X {int i;} *)0;
// type name "struct X {int i;}*" used in the cast expression
// introduces the new type "struct X"
struct X x = {1}; // struct X is now in scope
