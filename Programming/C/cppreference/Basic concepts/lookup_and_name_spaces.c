struct A { };       // introduces the name A in tag name space
typedef struct A A; // first, lookup for A after "struct" finds one in tag name space
                    // then introduces the name A in the ordidnary name space

struct A* p;        // OK, this A is looked up in the tag name space
A* q;               // OK, this A is looked up in the ordinary name space

void foo (void) { return; } // ordinary name space, file scope
struct foo {      // tag name space, file scope
    int foo;      // member name space for this struct foo, file scope
    enum bar {    // tag name space, file scope
        RED       // ordinary name space, file scope
    } bar;        // member name space for this struct foo, file scope
    struct foo* p; // OK: uses tag/file scope name "foo"
};
enum bar x; // OK: uses tag/file-scope bar
// int foo; // Error: ordinary name space foo already in scope 
//union foo { int a, b; }; // Error: tag name space foo in scope

int main() {
    struct tagged_union {
        enum {INT, FLOAT, STRING} type;
        union {
            int ineger;
            float floating_point;
            char *string;
        } value;
    } tu;
    tu.type = INT;

    goto foo; // OK uses "foo" from label name space/function scope

    struct foo { // tag name space, block scope (hides file scope)
        enum bar x; // OK, uses "bar" from tag name space/file scope
    };
    typedef struct foo foo; // OK: uses foo from tag name space/block scope
                            // // defines block-scope ordinary foo (hides file scope)
    (foo){.x = RED}; // uses ordinary/block-scope foo and ordinary/file-scope RED

foo:; // label name space, function scope
}
