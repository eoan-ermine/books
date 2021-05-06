pub fn main() {
	let mut number = String::new();
	std::io::stdin().read_line(&mut number).expect("Failed to read a line");
	let number = number.parse::<i32>().expect("Please, enter valid integer");

	println!("{} is {}", number, if number % 2 == 0 {
		"even"
	} else {
		"odd"
	});
}