fn main() {
	let mut name = String::new();
	std::io::stdin().read_line(&mut name).expect("Failed to read a line");

	println!("Hello, {}", name);
}