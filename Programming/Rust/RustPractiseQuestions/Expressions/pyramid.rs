pub fn main() {
	let mut length = String::new();
	std::io::stdin().read_line(&mut length).expect("Failed to read a line");
	let length = length.parse::<usize>().expect("Please, enter valid integer");

	if length % 2 == 0 {
		panic!("Please, enter odd length");
	}

	let spaces = length / 2;
	let symbol = "*";

	for i in (0..=spaces).rev() {
		println!("{s}{}{s}", symbol.repeat(length - (i * 2)), s=" ".repeat(i));
	}
}