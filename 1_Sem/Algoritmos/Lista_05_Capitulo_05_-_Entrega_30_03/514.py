num = 0
media = 0
soma = 0
x = 0
while(True):
    num = int(input("Informe um número: "))
    if num == 0:
        break
    print("Número computado.")
    x += 1
    soma += num
media = soma/x
print("Soma: %i \nMédia aritmética: %i" %(soma, media))