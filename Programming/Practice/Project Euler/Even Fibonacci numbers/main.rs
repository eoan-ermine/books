#![feature(generator_trait)]

use std::ops::{Generator, GeneratorState};
use std::pin::Pin;

pub struct FibonacciGenerator {
    first: Option<i64>,
    second: Option<i64>,
    limit: i64,
}

impl FibonacciGenerator {
    pub fn new(limit: i64) -> Self {
        Self {
            first: None,
            second: None,
            limit 
        }
    }
}

impl Default for FibonacciGenerator {
    fn default() -> Self {
        Self::new(4000000)
    }
}

impl Generator for FibonacciGenerator {
    type Yield = i64;
    type Return = ();

     fn resume(mut self: Pin<&mut Self>, arg: ()) -> GeneratorState<Self::Yield, Self::Return> {
        if let None = self.first {
            self.first = Some(0);
            GeneratorState::Yielded(0)
        } else if let None = self.second {
            self.second = Some(1);
            GeneratorState::Yielded(1)
        } else {
            let temporary: i64 = self.second.unwrap();

            let new_value = self.second.unwrap() + self.first.unwrap();

            if new_value > self.limit {
                GeneratorState::Complete(())
            } else {
                self.second = Some(new_value);
                self.first = Some(temporary);
    
                GeneratorState::Yielded(new_value)    
            }
        }
    }
}

fn main() {
    let mut result: i64 = 0;

    let mut generator = FibonacciGenerator::default();
    loop {
        result += {
            if let GeneratorState::Yielded(value) = Pin::new(&mut generator).resume(()) {
                if value % 2 == 0 {
                    value
                } else {
                    0
                }
            } else {
                break;
            }
        }    
    }
    println!("{}", result);
}