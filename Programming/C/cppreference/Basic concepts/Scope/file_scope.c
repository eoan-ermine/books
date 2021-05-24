int i; // scope of i begins
static int g(int a) { return a; } // scope of g begins ('a' has block scope)
int main() {
    i = g(2); // i and g are in scope
}

// Scope of any ident declared outside of
// any block of param list begins at
// the point of declaration and
// ends at the end of the translation unit

// External linkage and static storage duration
// by default