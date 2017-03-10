num = int(input("Informe um numero: "))
if num == 2 or num == 3:
    print("É primo.")
elif ((num == 0) or (num == 1) or (num % 2 == 0)):
    print("Não é primo.")
else:
    x = 3
    while x < num:
        resto = num % x
        x += 2
        if resto == 0:
            print("Não é primo.")
        else:
            print("É primo.")
            break