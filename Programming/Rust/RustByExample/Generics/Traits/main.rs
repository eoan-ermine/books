struct Empty;
struct Null;

trait DoubleDrop<T> {
    fn double_drop(self, _: T);
}

impl<T, U> DoubleDrop<T> for U {
    fn double_drop(self, _: T) {}
}

fn main() {
    let empty = Empty;
    let null = Null;

    // Deallocate `empty` and `null`
    empty.double_drop(null);

    // Error if uncommented:
    // empty;
    // null;
}