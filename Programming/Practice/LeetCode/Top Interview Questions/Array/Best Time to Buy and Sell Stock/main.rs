impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        prices.windows(2).map(|window| {
            let y = window[1];
            let x = window[0];
            
            if(y > x) { y - x } else { 0 } 
        }).sum()   
    }
}