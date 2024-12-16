module Main where

lista = [30,29..1]
triplicar x = 3 * x

main = do
  print(last (reverse (map triplicar lista)))