pub struct Student {
    roll: i32,
    name: String,
    age: u8,
    marks: Vec<u8>
}

pub fn main() {
    let student = Student {
        roll: 10,
        name: String::from("John"),
        age: 10_u8,
        marks: vec![1, 2, 3, 4, 5, 1, 2, 3, 4, 5]
    };
}