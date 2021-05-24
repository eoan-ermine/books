// #pragma STDC FENV_ACCESS OFF|ON
// If ON - informs compiler that he program will access or modify
// floating-point enironment - prohibit some optimisations
// Default - impl defined, usually

// #pragma STDC FP_CONTRACT OFF|ON
// Allows contracting of floating-point expressions, that is
// optimizations that omit rounding errors and floating-point
// expections
// Default value - impl defined, usually on

// #pragma STDC CX_LIMITED_RANGE OFF|ON
// Informs the compiler that multiplication, division, and
// absolute value of complex numbers may use simplified
// mathematical formulas. But intermediate overflow is possible
// so, programmer guarantees that the range of the values is limited
// Default - OFF

// NON-STANDARD PRAGMAS

// #pragma once

// equal to

// #ifndef LIBRARY_FILENAME_H
// #define LIBRARY_FILENAME_H
// // contents of the header
// #endif

// #pragma pack

// Control the max alignment for subsequently defined
// structure and union members

// #pragma pack(arg)
// Sets the current alignmnent to value arg

// #pragma pack()
// Sets the current alignment to the default value

// #pragma pack(push)
// Pushes the value of the current alignment on an internal stack

// #pragma pack(push, arg)
// #pragma pack(push) and #pragma pack(arg)

// #pragma pack(pop)
// Pops the top entry from stack and sets current alignment to that value

// May decrease the align but cannot make struct overaligned