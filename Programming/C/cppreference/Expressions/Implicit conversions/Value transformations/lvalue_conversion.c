int main() {
    // Any lvalue expression of any non-array type, when used
    // in any context other than
    //  * as the operand of the address-of-operator
    //  * as the operand of inc/dec operators
    //  * as the left-hand operand of the member access operator
    //  * as the left-hand operand of the assignment and
    //    compound assignment operators
    //  * as the operand of sizeof

    // undergoes lvalue conversion: the type remains the same,
    // but loses const/volatile/restrict-qualifiers and atomic
    // properties, if any. The value remains the same, but
    // loses its lvalue properties

    // if lvalue has incomplete type -> UB
    // if auto storage duration and uninit -> UB
    
    // conversion models the memory load
    // of the value of the obj from
    // its location

    volatile int n = 1;
    int x = n; // lvalue conversion on n reads the value of n
    volatile int* p = &n; // no lvalue conversion: does not read the value of n
}