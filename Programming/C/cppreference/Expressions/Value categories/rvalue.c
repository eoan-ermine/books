// Non-lvalue obj exprs are the exprs of object types that
// do not designate objects, but rather values that have no
// object identity or storage location
// The address of a rvalue obj expr cannot be taken

// The following exprs are rvalue object exprs:
//  * integer, character, and floating constants
//  * all operators not specified to return lvalues, including
//      * any function call expression
//      * any cast expression
//      * member access operator applied to a rvalue
//        structure/union
//      * all arithmetic, relational, logical, and bitwise
//        operators
//      * increment and decrement operators
//      * assignment and compound assignment operators
//      * the conditional operator
//      * the comma operator
//      * the address-of operator

// Expressions of type void are assumed to be rvalue object
// expressions

// Struct/union rvalue that has a member of array type
// in fact designate and objec with temporary lifetime