// The scope of a struct, union and enum tags
// begins immediately after the appearance
// of the tag in a type specifier that declares
// the tag.

struct Node {
    struct Node* next; // Node is in sope and refers to this struct
};

// The scope of enumeration constant
// begins immediately after the appearance
// of its defining enumerator in an
// enumerator list. 

int main() {
    enum {x = 12};
    {
        enum {  x = x + 1, // new x is not in scope until the comma, x = 13
                y = x + 1 // the new enumerator x is now in scope, y = 14
            };
    }

    // The scope of any other ident begins
    // just after the end of its declarator
    // and before the initializer

    int z = 2; // scope of the first 'z' begins
    {
        int z[z]; // scope of the newly declared x begin after the declarator (x[x]]).
                  // Withing the declarator, the outer 'x' is still in scope
                  // This declares a VLA array of 2 int
    }
    unsigned char w = 32; // scope of the outer 'x' begins
    {
        unsigned char w = w;
            // scope of the inner 'x' begins before the initializer
            // this does not initialize the inner 'x' with the value 32,
            // this initialize the inner 'x' with its own, indeterminate, value
    }
}

unsigned long factorial(unsigned long n) {
    // declarator ends, 'factorial' is in scope from this point
    return n < 2 ? 1 : n * factorial(n - 1);
}
