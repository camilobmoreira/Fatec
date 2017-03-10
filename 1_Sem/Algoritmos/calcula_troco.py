valor = int(input("Digite o valor que será pago: R$"))
conta = int(input("Digite o valor da conta: R$"))
cedulas = 0
apagar = valor
print("O troco deverá ser nas seguintes notas")
while True:
    if conta <= apagar:
        apagar -= conta
        cedulas += 1
    else:
        print("%i cédula(s) de R$%i" % (cedulas, conta))
        if apagar == 0:
            break
        if conta == 50:
            conta = 20
        elif conta == 20:
            conta = 10
        elif conta == 10:
            conta = 5
        elif conta == 5:
            conta = 2
        elif conta == 2:
            conta = 1
        cedulas = 0