n = int(input("Tabuada de: "))
x = int(input("Começando em: "))
y = int(input("Terminando em: "))
while x <= y:
    print("%i x %i = %i" %(n, x, (n * x)))
    x = x + 1