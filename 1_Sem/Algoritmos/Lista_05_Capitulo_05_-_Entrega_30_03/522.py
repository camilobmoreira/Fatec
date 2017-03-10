
while(True):
    op = input("Informe o número ou o simbolo da operação desejada: \n1 - soma (+); \n2 - subtração (-); \n3 - multiplicação (*); \n4 - divisão (/); \n5 - sair. \n").lower()
    a = 0
    if(op == "1" or op == "+"):
        while a <= 10:
            b = 0
            while b <= 10:
                print(" %i + %i é: %i" %(a, b, a + b))
                b += 1
            print("\n")
            a += 1
        break
    elif(op == "2" or op == "-"):
        while a <= 10:
            b = 0
            while b <= 10:
                print(" %i - %i é: %i" % (a, b, a - b))
                b += 1
            print("\n")
            a += 1
        break
    elif(op == "3" or op == "*"):
        while a <= 10:
            b = 0
            while b <= 10:
                print(" %i * %i é: %i" % (a, b, a * b))
                b += 1
            print("\n")
            a += 1
        break
    elif(op == "4" or op == "/"):
        while a <= 10:
            b = 0
            while b <= 10:
                print(" %i / %i é: %i" % (a, b, a / b))
                b += 1
            print("\n")
            a += 1
        break
    elif(op == "5" or op == "sair"):
        break
    else:
        print("Operação inválida.")
