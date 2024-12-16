module Main where

fatorial x
  | x > 1 = x * fatorial(x - 1)
  | otherwise = 1
  
funcaoparcial x
  | x > 0 = fatorial(x)
  | otherwise = 2 * x

main = do
  print(funcaoparcial(-5))