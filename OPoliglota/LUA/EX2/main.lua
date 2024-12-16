local matrix = {}

math.randomseed(os.time())

for i = 1, 100 do
  matrix[i] = math.random(1,100)
end

local counter = 0

for i = 1, 100 do
  if matrix[i] % 2 == 0 then
    counter = counter + 1
  end
end

print("Dos numeros sorteados ".. counter.."% são pares")