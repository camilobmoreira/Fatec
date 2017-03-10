num = -1
while num < 0:
    num = int(input("Informe um número: "))
    if num < 0:
        print("Informe um numero não negativo.")
a = 1
b = 2
c = 3
total = 0
while total < num:
    total = a * b * c
    if total == num:
        print("É um numero triangular. \nOs naturais consecutivos que resultam em %i são %i * %i * %i" %(num, a, b, c))
    else:
        a += 1
        b += 1
        c += 1
if total > num:
    print("Não é um número triangular.")