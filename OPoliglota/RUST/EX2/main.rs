use std::io;

pub fn main() {
  let mut arr:[i32;10] = [0; 10];

  println!("Digite um numero");
  let mut input = String::new();
  io::stdin().read_line(&mut input).expect("ermac");
  let num:i32 = input.trim().parse().expect("ermac");
  fullarray(&mut arr, num);

  for i in 0..arr.len() {
    println!("{}", arr[i]);
  }
}

pub fn fullarray(arr: &mut [i32], x: i32) {
  for i in 0..arr.len() {
    arr[i] = x * (i as i32);
  }
}