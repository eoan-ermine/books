void f(int y) {}

int main() {
    int i = 0, a[5];

    // If a side effect on a scalar object is unsequenced
    // relative to another side effect on the same scalar object
    // behavior is undefined

    i = ++i + i++; // UB
    i = i++ + 1; // UB
    f(++i, ++i); // UB
    f(i = -1, i = -1); // UB

    // If a side effect on a scalar object is unsequenced
    // relative to a value computation using the value
    // of the same scalar object, the behavior is undefined

    f(i, i++); // UB
    a[i] = i++; // undefined behavior

    // The above rules apply as long as at least one allowable
    // ordering of subexpressions permits such an
    // unsequenced side-effect
}