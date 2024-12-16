10 INPUT "Digite o limite superior (nao incluso) : "; lim
20 LET rng = rnd(lim)

30 LET fact = 1

40 FOR i = 1 TO rng STEP 1
50 fact = fact*i
60 NEXT i

70 PRINT fact
END