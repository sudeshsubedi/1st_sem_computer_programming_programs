use std::io;

fn main() {
    let mut num = String::new();
    println!("Enter a number: ");
    io::stdin()
        .read_line(&mut num)
        .expect("Failed to read line");
    let num: i128 = num.trim().parse().expect("Please type a number!");

    println!("{}! = {}", num, factorial(num));
}

fn factorial(mut n: i128) -> i128 {
    let mut fact : i128 = 1;
    if n < 0 {
        return n;
    } else if n < 2 {
        return 1
    }
    while n > 1 {
        fact *= n;
        n -= 1;
    }
    fact
}