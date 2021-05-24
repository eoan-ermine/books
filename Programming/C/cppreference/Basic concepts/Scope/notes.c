// Local variables within a loop body can hide
// variables declared in the init clause of
// a for loop in C, but cannot do that in C++

// C has no struct scope (expect that data members are in their own member name space):

struct foo {
    struct baz {};
    enum color { RED, BLUE };
};

struct  baz b; // baz in scope
enum color x = RED; // color and RED are in scope

int main() {}