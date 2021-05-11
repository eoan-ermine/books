struct A;
struct S(A);
struct SGen<T>(T);

// Not a generic function
fn reg_fn(_s: S) {}

// Not a generic function
fn gen_spec_t(_s: SGen<A>) {}

// Not a generic function
fn gen_spec_i32(_s: SGen<i32>) {}

// Generic function
fn generic<T>(_s: SGen<T>) {}

fn main() {
    reg_fn(S(A));
    gen_spec_t(SGen(A));
    gen_spec_i32(SGen(6));

    generic::<char>(SGen('a'));
    generic(SGen('c'));
}