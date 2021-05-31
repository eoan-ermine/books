int main() {
    // Any function designator expr, when used in any context other than
    //  * as the operand of the address-of operator
    //  * as the operand of sizeof

    // undergoes a conversion to the non-lvalue pointer to the function designated
    // by the expression

    int f(int);
    int (*p)(int) = f; // conversion to &f
    (***p)(1); // repeated dereference to f and conversion back to &f
}