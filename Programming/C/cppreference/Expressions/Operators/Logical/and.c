#include <stdbool.h>
#include <stdio.h>

/*
Form: lhs && rhs,
where
    lhs - an expression of any scalar type
    rhs - an expression of any scalar type, which is only evaluated
          if lhs does not compare equal to 0
Return value: int (zero or one) 
*/

int main(void) {
    bool b = 2+2==4 && 2*2==4; // b == true

    1 > 2 && puts("this won't print");

    char *p = "abc";
    if(p && *p) {   // common C idiom: if p is not null
                    // AND if p does not point at the end of the string
    }               // then do some string processing
}