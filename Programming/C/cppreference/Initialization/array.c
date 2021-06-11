#include <wchar.h>

void from_strings() {
    // ordinary string literals and UTF-8 string literals can
    // initialize arrays of any character type

    // L-prefixed wide string literals can be used to initialize array
    // of any type compatible with wchar_t

    // u-prefix -> with char16_t
    // U-prefixed -> with char32_t

    char str[] = "abc"; // str has type char[4] and holds 'a', 'b', 'c', '\0'
    wchar_t wstr[4] = L"猫"; // str has type wchar_t[4] and holds L'猫', '\0', '\0', '\0'

    char str[3] = "abc"; // str has type char[3] and holds 'a', 'b', 'c'

    // Contents of such array are modifable, unlike when accessing
    // a string literal directly with

    char* string = "abc";
}

void from_brace_enclosed_lists() {
    int x[] = {1,2,3}; // x has type int[3] and holds 1,2,3
    int y[5] = {1,2,3}; // y has type int[5] and holds 1,2,3,0,0
    int z[3] = {0}; // z has type int[3] and holds all zeroes

    int n[5] = {[4]=5,[0]=1,2,3,4}; // holds 1,2,3,4,5
    
    int MAX = 10;
    int a[MAX] = {
        1, 3, 5, 7, 9, [MAX-5] = 8, 6, 4, 2, 0
    };
    // for MAX = 6, array holds 1, 8, 6, 4, 2, 0
    // for MAX = 13, array holds 1,3,5,7,9,0,0,0,8,6,4,2,0
}

void nested_arrays() {
    int y[4][3] = {
        { 1 }, // row 0 = {1,0,0}
        { 0, 1 }, // row 1 = {0,1,0}
        { [2] = 1 }, // row 2 = {0,0,1}
    }; // row 3 = {0,0,0}

    int y[4][3] = { // array of 4 arrays of 3 ints each
        1, 3, 5, 2, 4, 6, 3, 5, 7   // row 0 initialized to {1, 3, 5}
    };                              // row 1 initialized to {2, 4, 6}
                                    // row 2 initialized to {3, 5, 7}
                                    // row 3 initialized to {0, 0, 0}
    
    struct { int a[3], b; } w[] = { {1}, 2 };
    // array of structs:
    //  #1 => { {1, 0, 0}, 0}
    //  #2 => { {2, 0, 0}, 0}

    int y[4][3] = {[0][0]=1, [1][1]=1, [2][0]=1}; // row 0 initialized to {1, 0, 0}
                                                  // row 1 initialized to {0, 1, 0}
                                                  // row 2 initialized to {1, 0, 0}
                                                  // row 3 initialized to {0, 0, 0}
}

void notes() {
    // The order of evaluation of subexpressions in an array initializer is indeterminately sequenced in C

    int n = 1;
    int a[2] = {n++, n++}; // unspecified, but well-defined
                           // a initialized to {1, 2} and to {2, 1} are both valid
    puts(
        (char[4]){'0'+n} + n++
    );  // undefined behavior: increment and read from n are unsequenced

    int a[3] = {0}; // valid C and C++ way to zero-out a block-scope array
//  int a[3] = {}; // invalid C but valid C++ way to zero-out a block-scope array

//    static char* p[2] = {malloc(1), malloc(2)}; // error
}

int main(void) {
    // The following four array declarations are the same
    short q1[4][3][2] = {
        { 1 },
        { 2, 3 },
        { 4, 5, 6 }
    };
 
    short q2[4][3][2] = {1, 0, 0, 0, 0, 0, 2, 3, 0, 0, 0, 0, 4, 5, 6};
 
    short q3[4][3][2] = {
        {
            { 1 },
        },
        {
            { 2, 3 },
        },
        {
            { 4, 5 },
            { 6 },
        }
    };
 
    short q4[4][3][2] = {1, [1]=2, 3, [2]=4, 5, 6};

    // Character names can be associated with enumeration constants
    // using arrays with designators:
    enum { RED, GREEN, BLUE };
    const char *nm[] = {
        [RED] = "red",
        [GREEN] = "green",
        [BLUE] = "blue",
    };
}