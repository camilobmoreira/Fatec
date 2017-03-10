fim = int(input("Digite o último número a imprimir: "))
x = 0
while x <= fim:
    if(x % 3 == 0):
        print(x)
    x = x + 1