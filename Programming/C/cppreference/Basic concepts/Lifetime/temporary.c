struct T { double a[4]; };
struct T f(void) { return (struct T){3.15}; }
double g1(double* x) { return *x; }
void g2(double* x) { *x = 1.0; }

int main() {
    double d = g1(f().a); // C99: UB access to a[0] in g1 whose lifetime ended
                          // at the sequence point at the start of g1
                          // C11: OK, d is 3.15

    g2(f().a); // C99: UB modification of a[0] whose lifetime ended at the sequence point
               // C11: UB attempt to modify a temporary object
}