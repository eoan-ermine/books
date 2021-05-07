pub fn main() {
    let result = (1..=9).zip(
        1..=9
    );
    for (x, y) in result {
        println!("{} * {} = {}", x, y, x * y);
    }
}