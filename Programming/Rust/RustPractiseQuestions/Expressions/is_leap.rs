pub fn is_leap(year: i32) -> bool {
    (year % 4) && (year % 100 != 0 || year % 400 == 0)
}

pub fn main() {}