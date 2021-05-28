// An integer constant expression is an expression that consists only of

// * operators other than assignment, increment, decrement, function-call,
//   or comma, except that cast operators can only cast arithmetic types
//   to integer types
// * integer constants
// * enumeration constants
// * character constants
// * floating constants, but only if they are immediately used as operands
//   of casts to integer types
// * sizeof operators whose operands are not VLA
// * _Alignof operators

// These expressions are evaluated at compile time
// The following contexts require expressions that are known as integer constant
// expressions:

// * The size of a bit field
// * The value of an enumeration constant
// * The case label of a switch statement
// * The size of a non-VLA array
// * Integer to pointer implicit conversion
// * The index in an array designator
// * The first argument of _Static_assert
// * The integer argument of _Alignas
