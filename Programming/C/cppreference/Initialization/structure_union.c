#include <stdint.h>;

#include <stdio.h>;
#include <time.h>;

void explanation() {
    // When initializing a union, the initializer
    // list must have only one member

    union { int x; char c[4]; }
        u = {1},    // makes u.x active with value 1
        u2 = {.c = {'\1'}}; // makes u2.c active with value {'\1', '\0', '\0', '\0'}
    
    struct point { double x, y, z; } p = {1.2, 1.3}; // p.x = 1.2, p.y = 1.3, p.z=0.0
    struct {
        int rem; int quot;
    } answer = {.quot = 2, .rem = -1 };
    struct {
        int sec, min, hour, day, mon, year;
    } z = {.day=31,12,2014,.sec=30,15,17}; // initializes z to {30,15,17,31,12,2014}
}

void nested_initialization() {
    struct example {
        struct addr_t {
            uint32_t port;
        } addr;
        union {
            uint8_t a8[4];
            uint16_t a16[2];
        } in_u;
    };
    struct example ex = { // start of initializer list for struct example
        { // start of initializer list for ex.addr
            80 // initialized struct's only member
        }, // end of initializer list for ex.addr
        { // start of initializer-list for ex.in_u
            {127,0,0,1} // initializes first element of the union
        }
    };
    struct example ex2 = {
        .in_u.a8[0]=127, 0, 0, 1, .addr=80
    };
    struct example ex3 = {
        80, .in_u = { // changes current object to the union ex.in_u
            127,
            .a8[2] = 1 // this designator refers to the member of in_u
        }
    };

    struct { int n; } s = {
        printf("a\n"), // this may be printed or skipped
        .n=printf("b\n") // always printed
    };

    typedef struct {
        int k; int l; int a[2];
    } T;
    typedef struct {
        int i; T t;
    } S;

    T x = {.l = 43, .k = 42, .a[1] = 19, .a[0] = 18};
    // x is initialized to {42, 43, {18, 19}}

    S l = {
        1,
        .t = x,
        .t.l = 41,
        .t.a[1] = 17
    };
    printf("l.t.k is %d\n", l.t.k); // clang (correct): .t = x sets l.t.k to 42 explicitly
                                    // gcc: .t.l = 41 would zero out l.t.k implicitly

    // However, when an initializer begins with a left open brace,
    // its current object is fully re-initialized
    // any prior explicit initializers for any of its subobjects
    // are ignored

    struct fred { char s[4]; int n; };
    struct fred x[] = {
        {
            { "abc" }, 1
        }, // inits x[0] to {{'a','b','c','\0'}, 1}
        [0].s[0] = 'q'
    };
    struct fred y[] = {
        {
            { "abc" }, 1
        }, // inits y[0] to {{'a','b','c','\0'}, 1}
        [0] = {
            .s[0] = 'q'
        } // replaces y[0] with { {'q', '\0', '\0', '\0' }, 0}
    };
}

void notes() {
    struct {
        double x, y;
    } p = {
        1.0,
        2.0,
    }; // May have trailing comma, which is ignored

    struct {
        int n;
    } s = {0}; // OK
/*  struct {
        int n;
    } s = {}; // Error: initializer-list cannot be empty */
/*  struct {
    } s = {}; Error: struct cannot be empty, initializer-list cannot be empty */

/*  static struct {
        char* p
    } s = { malloc(1) }; // Error */

    // The order or evaluation of subexpressions
    // int any initializer is indeterminately sequenced:

    int n = 1;
    struct {
        int x, y;
    } p = {n++, n++}; // unspecified,
                      // both {1, 2} and {2, 1} are valid
}

int main() {
    char buff[70];
    // designated initializers simplify the use of structs whose
    // order of members is unspecified
    struct tm my_time = {
        .tm_year=112, .tm_mon=9, .tm_mday=9,
        .tm_hour=8, .tm_min=10, .tm_sec=20
    };
    strftime(buff, sizeof buff, "%A %c", &my_time);
    puts(buff);
}