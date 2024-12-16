class Carro
  def descrever
    puts "Este é um carro normal"
  end
end

class CarroEsporte < Carro
  def descrever
    puts "Este é um carro esporte"
  end
end

class CarroSedan < Carro
  def descrever
    puts "Este é um carro sedan"
  end
end

carro = Carro.new
carroesporte = CarroEsporte.new
carrosedan = CarroSedan.new

carro.descrever
carroesporte.descrever
carrosedan.descrever