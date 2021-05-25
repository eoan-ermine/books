// * If a sequence point is present between the subexpressions
// E1 and E2, then both value computation and side effects
// of E1 are sequenced-before every value computation
// and side effect of E2

// * If evaluation A is sequence before evaluation B, then
// evaluation of A will be complete before evaluation of B
// begins

// * If A is not sequenced before B and B is sequenced before
// A, then evaluation of B will be complete before evaluation
// of A begins

// * If A is not sequenced before B and B is not sequenced
// before A, then two possibilities exist:
//      * evaluation of A and B are unsequenced: they may
//        be performed in any order and may overlap
//      * evaluations of A and B are indeterminably-seque
//        nced: they may be performed in any order but may
//        not overlap