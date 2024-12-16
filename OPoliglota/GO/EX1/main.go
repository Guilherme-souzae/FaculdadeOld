package main

import (
	"math"
	"fmt"
	"strconv"
)

func equacionar(a float64, b float64 ,c float64) {
	if (a == 0) {
		fmt.Println("A equacao nao e de segundo grau")
		return
	} else if (b*b-4*a*c < 0) {
		fmt.Println("Nao existe raiz real")
	} else {
		delta := b*b - 4*a*c
		x1 := (-b + math.Sqrt(delta)) / (2 * a)
		x2 := (-b - math.Sqrt(delta)) / (2 * a)
		fmt.Println("As raizes sao: ",x1," e ",x2)
	}
}

func main() {
	var input string
	fmt.Println("Digite os coeficientes A B C:")

	fmt.Scanln(&input)
	a, _ := strconv.ParseFloat(input, 32)

	fmt.Scanln(&input)
	b, _ := strconv.ParseFloat(input, 32)

	fmt.Scanln(&input)
	c, _ := strconv.ParseFloat(input, 32)

	equacionar(a, b, c)
}
