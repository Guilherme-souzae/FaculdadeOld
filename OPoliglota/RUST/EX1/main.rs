use std::io;

pub fn main() {
    loop {
        let mut input = String::new();
        let mut ninput1 = String::new();
        let mut ninput2 = String::new();
        let mut inputop = String::new();
        
        println!("digite 'calcular' para calcular");
      
        io::stdin().read_line(&mut input).expect("Falha ao ler a entrada");

        let input = input.trim();

        if input != "calcular" {
            break;
        }
      
        println!("Digite o primeiro número:");
        io::stdin().read_line(&mut ninput1).expect("Falha ao ler a entrada");
        println!("Digite o segundo número:");
        io::stdin().read_line(&mut ninput2).expect("Falha ao ler a entrada");

        let num1: i32 = ninput1.trim().parse().unwrap();
        let num2: i32 = ninput2.trim().parse().unwrap();

        println!("Digite a operação (+, *):");
        io::stdin().read_line(&mut inputop).expect("Falha ao ler a entrada");

        let inputop = inputop.trim();

        if inputop == "+" {
            println!("Resultado: {}", num1 + num2);
        }
        else if inputop == "*" {
            println!("Resultado: {}", num1 * num2);
        }
        else {
            println!("Operação inválida");
        }
    }
}
