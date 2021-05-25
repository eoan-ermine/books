#include <stdbool.h>

int f(int arg) {
    return arg + 1;
}

int main() {
    // There is a sequence point:

    // * after the evaluation of all function arguments and of
    // the function designator, and before the actual
    // function call

    f(5 + 5); // 5 + 5 calculates and then function call
              // occures

    // * after evaluation of the first operand and before
    // evaluation of the second one of the following
    // binary operators: &&, ||, comma (,)

    (5 == 5) || (2 == 1), (5 == 5) && (12 % 4 == 0);

    // * after evaluation of the first operand and before
    // evaluation of the second or third operand of the
    // conditional operator ?:

    printf("%s", (4 % 2 == 0) ? "true" : "false");

    // firstly, (4 % 2 == 0) evaluates, if it's true, then
    // second operand evaluates, else third operand evaluates

    // * after the evaluation of a full expression and before the
    // next full expression

    /* 1 */ (5 + 5) / (2);
    /* 2 */ (4 * 4) / 4;

    // evaluates 1 -> 2

    // * at the end of a full declarator

    // * immediately before the return of a library function
    
    // * after the action associated with each conversion
    //   specifier in formatted I/O

    // * before and immediately after each call to a
    //   comparison function made by the library functions
    //   qsort and bsearch

    // * the value computations of the operands to any operator
    //   are sequenced before the value computation of the
    //   result of the operator (but not its side-effects)

    // * The side effect of the direct assignment operator
    //   and of all compound assignment operators is 
    //   sequenced after the value computation (but not side effects)
    //   of both left and right arguments

    // * The value computation of the postincrement and 
    //   postdecrement operators is sequenced before its
    //   side-effect

    // * A function call that is not sequenced before or
    //   sequenced after another func call is indeterminately
    //   sequenced

    // * In initialization list expressions, all evaluations
    //   are indeterminately sequenced

    // * The operation of compound assignment operators,
    //   and both prefix and postfix forms of increment and
    //   decrement operators are single evaluations
}