using System;

class Cachorro {
  public String Nome {get; set;}
  public int Idade {get; set;}

  public Cachorro(String nome, int idade) {
    Nome = nome;
    Idade = idade;
  }

  public void showNome() {
    Console.WriteLine("O nome do cachorro é: " + Nome);
  }

  public virtual void showIdade() {
    Console.WriteLine("A idade do cachorro é: " + Idade);
  }
}

class CachorroGrande : Cachorro {
  private int Tamanho;
  public CachorroGrande(String nome, int idade, int tamanho) : base(nome, idade) {
    Tamanho = tamanho;
  }

  public override void showIdade() {
    Console.WriteLine("A idade do cachorro grande é: " + Idade);
  }
}

class CachorroPequeno : Cachorro {
  public CachorroPequeno(String nome, int idade) : base(nome, idade) {
  }

  public override void showIdade() {
    Console.WriteLine("A idade do cachorro pequeno é: " + Idade);
  }
}

class Program {
  public static void Main (string[] args) {
    Cachorro cachorro = new Cachorro("D-Dog", 5);
    CachorroGrande cachorrogrande = new CachorroGrande("Sif", 1000, 5);
    CachorroPequeno cachorropequeno = new CachorroPequeno("Rush", 3);

    cachorro.showNome();
    cachorro.showIdade();

    cachorrogrande.showNome();
    cachorrogrande.showIdade();

    cachorropequeno.showNome();
    cachorropequeno.showIdade();
  }
}