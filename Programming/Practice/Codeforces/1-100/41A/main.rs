use std::cmp::Ordering;

fn main() {
        let mut lhs = String::new();
        let mut rhs = String::new();
    
        std::io::stdin().read_line(&mut lhs).unwrap();
        std::io::stdin().read_line(&mut lhs).unwrap();

        println!("{}", if lhs[..].chars().rev().cmp(rhs.chars()) == Ordering::Equal { "YES" } else { "NO" } );
}
