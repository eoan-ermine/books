int main() {
    // Any lvalue expr of array type, when
    // used in any context other than
        // * as the operand of the address-of operator
        // * as the operand of sizeof
        // * as the string literal used for array initialization
    // undergoes a conversion to the non-lvalue pointer to its first element

    // if array declared register -> UB

    int a[3], b[3][4];
    int *p = a; // conversion &a[0]
    int (*q)[4] = b; // conversion to &b[0]
}