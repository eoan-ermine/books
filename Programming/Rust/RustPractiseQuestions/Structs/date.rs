use std::convert::TryFrom;

pub struct Date {
    day: u8,
    month: u8,
    year: u32,
}

impl TryFrom<&str> for Date {
    type Error = ();

    fn try_from(value: &str) -> Result<Self, Self::Error> {
        let mut iter = value.split(".");

        let day: u8 = iter.next().ok_or(())?.parse().map_err(|_| ())?;
        let month: u8 = iter.next().ok_or(())?.parse().map_err(|_| ())?;
        let year: u32 = iter.next().ok_or(())?.parse().map_err(|_| ())?;
        
        Ok(Self {
            day,
            month,
            year
        })
    }
}

impl PartialEq for Date {
    fn eq(&self, other: &Self) -> bool {
        self.day == other.day && self.month == other.month && self.year == other.year  
    }
}

pub fn main() {
    let mut buffer = String::new();
    std::io::stdin().read_line(&mut buffer).expect("Failed to read a line");

    let date1 = Date::try_from(buffer.as_str()).expect("Please, enter valid date in DD.MM.YY format");
    
    buffer.clear();
    std::io::stdin().read_line(&mut buffer).expect("Failed to read a line");

    let date2 = Date::try_from(buffer.as_str()).expect("Please, enter valid date in DD.MM.YY format");

    println!("First date is {} to second date",
        if date1 == date2 {
            "equal"
        } else {
            "not equal"
        }
    );
}