// The scope of a name introduced
// in the parameter list of a function
// declaration that is not a definition
// ends at the end of the function declarator

int f(int n, int a[n]); // n is in scope and refers to the first parameter

void g( // function name 'f' is at file scopes
    long double f, // the ident 'f' is now in scope, file-scope 'f' is hidden
    char (**a)[10 * sizeof f] // 'f' refers to the first parameter, which is in scope
);

enum{n = 3};
int (*(*d)(int n))[n]; // the scope of the function parameter 'n'
                       // ends at the end of its function declarator
                       // in the array declarator, global n is in scope
// (this declares a pointer to function returning a pointer to an array of 3 int)

int main() {}