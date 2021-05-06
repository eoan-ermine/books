pub fn factorial(n: i32) -> Result<i32, &'static str> {
	match n {
		1 | 2 => Ok(1),
		_ if n <= 0 => Err("n can't be negative"),
		x => Ok(factorial(x - 2)? + factorial(x - 1)?)
	}
}

pub fn main() {
	loop {
		let mut number = String::new();
		std::io::stdin().read_line(&mut number).expect("Failed to read a line");
		let number: i32 = number.parse().expect("Please, enter valid number");

		match factorial(number) {
			Ok(e) => println!("Factorial of {} is {}", number, e),
			Err(_) => {
				println!("Please, enter valid number");
				continue;
			}
		}
	}
}