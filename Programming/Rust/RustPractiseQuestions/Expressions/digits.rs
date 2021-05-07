pub fn name_digit(n: i32) {
    println!("{}", match n {
        1 => "one",
        2 => "two",
        3 => "three",
        4 => "four",
        5 => "five",
        6 => "six",
        7 => "seven",
        8 => "eight",
        9 => "nine",
        _ => "NaN"
    });
}

pub fn main() {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed to read a line");
    name_digit(buffer.parse().expect("Failed to parse a number"));
}