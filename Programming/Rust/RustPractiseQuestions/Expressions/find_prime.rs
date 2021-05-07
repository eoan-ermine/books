pub fn greater_than(vec: &Vec<Option<i32>>, n: i32) -> Option<i32> {
    for i in vec {
        if let &Some(e) = i {
            if e > n {
                return Some(e);
            }
        }
    }
    None
}

pub fn prime_nums(n: i32) -> Vec<i32> {
    let mut numbers: Vec<Option<i32>> = (2..=n).map(|x| Some(x)).collect();
    let mut p = 2;

    while let Some(e) = greater_than(&numbers, p) {
        for i in ((2 * p - 1)..=(n - 1)).filter(|x| (x + 1) % p == 0)  {
            numbers[(i - 1) as usize] = None;
        }
        p = e;
    }

    numbers.iter().filter(|e| e.is_some()).map(|x| x.unwrap()).collect()
}

pub fn main() {
    println!("{}", prime_nums(100).iter().map(i32::to_string).collect::<Vec<String>>().join(", "));   
}