#include <stdio.h>

struct s { int x; };
struct s f(void) { return (struct s){1}; }

int main(void) {
    struct s s;
    s.x = 1; // ok, changes the member of s

    int n = f().x; // f() is an expression of type struct s
//  f().x = 1; // Error: this members access expression is not an lvalue

    const struct s sc;
//  sc.x = 3; // Error: sc.x is const, can't be assigned

    union { int x; double d; } u = {1};
    u.d = 0.1; // changes the active member of the union

    struct s d = {1}, *p = &s;
    p->x = 7; // changes the value of s.x through the pointer
    printf("%d\n", p->x); // print 7
}