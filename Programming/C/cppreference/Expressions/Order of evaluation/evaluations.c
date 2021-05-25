// There are two kinds of evaluations performed by the compiler
// for each expressions or subexpression (both are optional):

// 1) value computation: calculation of the value that is
// returned by the expression

// 2) side effect access to and object designated by a volatile
// lvalue, modification to an object, atomic synchronization,
// modifying a file, modifying the floating-point env, or
// calling a function that does any of those operations

// if no side effects are produced by an expressions and
// the compiler can determine that the value is not used,
// the expr may not be evaluated
