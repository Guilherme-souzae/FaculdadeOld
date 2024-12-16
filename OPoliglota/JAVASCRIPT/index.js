class Animal
  {
    constructor(nome, idade, especie)
    {
      this.nome = nome;
      this.idade = idade;
      this.especie = especie;
    }

    printinfo()
    {
      console.log("Nome: " + this.nome);
      console.log("Idade: " + this.idade);
      console.log("Especie: " + this.especie);
    }
  }

class Cachorro extends Animal
  {
    #raca
    constructor(nome, idade, especie, raca)
    {
      super(nome, idade, especie);
      this.#raca = raca;
    }

    printinfo()
    {
      console.log("Nome: " + this.nome);
      console.log("Idade: " + this.idade);
      console.log("Especie: " + this.especie);
      console.log("Raca: " + this.#raca);
    }
  }

class Gato extends Animal
  {
    constructor(nome, idade, especie, cores)
    {
      super(nome, idade, especie);
      this.cores = cores;
    }

    printinfo()
    {
      console.log("Nome: " + this.nome);
      console.log("Idade: " + this.idade);
      console.log("Especie: " + this.especie);
      console.log("Cores: " + this.cores);
    }
  }

animal = new Animal("Animal", 1, "Animal");
cachorro = new Cachorro("Cachorro",7,"Rojer","Pitbull");
gato = new Gato("Gato",5,"Feliciano",["Branco","Preto","Vermelho"]);

animal.printinfo();
cachorro.printinfo();
gato.printinfo();