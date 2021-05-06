pub fn main() {
	let mut n = String::new();
	std::io::stdin().read_line(&mut n).expect("Failed to read a line");
	let n = n.parse::<i32>().expect("Please, enter valid integer");

	let mut multiply_factor: i32 = 1;
	loop {
		println!("{}", n * multiply_factor);
		if multiply_factor == 10 {
			break
		}
		multiply_factor += 1;
	}
}