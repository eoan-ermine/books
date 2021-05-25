// Lvalue expression is any expression with object type other than
// the type void, which potentially designates an object.

// In other words, lvalue expression evaluates to the object
// identity

// Lvalue exprs can be used in following contexts:
//  * as the operand of the address-of operator (expect if the lvalue designates a bit field or was declared register)
//  * as the operand of the pre/post increment and decrement operators
//  * as the left-hand operand of the member access operator
//  * as the left-hand operand of the assignment and compound assignments operators

// If an lvaluee expression is used in any context other than
// sizeof, _Alignof, or the operators listed above, non-array
// lvalues of any complete type undergo lvalue conversion,
// which models the memory load of the value of the object
// from its location

// Array lvalues undergo array-to-pointer conversion when used
// in any context other than sizeof, _Alignof, address-of operator
// or array init from a string literal

// Following expressions are lvalues:
//  * identifiers
//  * string literals
//  * compound literals
//  * parenthesized expressions if the unparenthesized expr
//    is an lvalue
//  * the result of a member access operator if its left-hand
//    argument is lvalue
//  * the result of the inderection operator applied to a
//    pointer to object
//  * the result of the subscription operator

