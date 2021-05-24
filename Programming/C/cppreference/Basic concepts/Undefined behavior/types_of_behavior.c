// 1. Ovservable behavior

/* 
2. undefined behavior - there are no restrictions on the
behavior of the program. Examples of undefined behavior are
memory accesses outside of array bounds, signed integer
overflow, null pointer dereference, modification of the same
scalar more than once in an expression without sequence points,
access to an object through a pointer of a different type,
etc. Compilers are not required to diagnose undefined
behavior (although many simple situations are diagnosed), and
the compiled program is not required to do anything meaningful. 
*/

/*
3. unspecified behavior - two or more behaviors are permitted
and the implementation is not required to document the effects
of each behavior. For example, order of evaluation, whether
identical string literals are distinct, etc. Each unspecified
behavior results in one of a set of valid results and may
produce a different result when repeated in the same program. 
*/

/*
4. implementation-defined behavior - unspecified behavior
where each implementation documents how the choice is made.
For example, number of bits in a byte, or whether signed
integer right shift is arithmetic or logical. 
*/

/*
5. locale-specific behavior - implementation-defined behavior
that depends on the currently chosen locale. For example,
whether islower returns true for any character other than
the 26 lowercase Latin letters.
*/