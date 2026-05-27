use std::io;
use std::cmp::Ordering;
use rand::Rng;

fn main() {
    let random_number = rand::thread_rng().gen_range(1..101);
    // println!("Random Number: {random_number}");

    println!("Waiting for your input");

    let mut guess = String::new();
    io::stdin().read_line(&mut guess).expect("Failed to read line");

    let guess: u32 = guess.trim().parse().expect("Please enter a number.");

    match guess.cmp(&random_number) {
        Ordering::Less => println!("Too small!"),
        Ordering::Equal => println!("You WIN!!"),
        Ordering::Greater => println!("Too big!")
    }
}

/*
use asciigraph::{plot, Config};

fn main() {
    let data = vec![3.0, 4.0, 6.0, -1.0, 2.0];
    let graph = plot(&data, Config::default());

    println!("{graph}");
}
*/