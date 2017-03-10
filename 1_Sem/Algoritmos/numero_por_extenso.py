umDigito = ["zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"]

while True:
    num = input("Informe um número entre 0 e 99: ")

    if int(num) not in range(0, 100):
        while True:
            op = input("Numero informado invalido. Digite S para sair ou N para informar novo número: ").lower()
            if op not in "sn":
                continue
            else:
                break
        if op == "s":
            break
        elif op == "n":
            continue

    num = int(num)
    num = str(num)

    numExtenso = ""

    if int(num) in range(0, 10):
        numExtenso = umDigito[int(num)].capitalize()
    elif int(num) == 10:
        numExtenso = "Dez"
    elif int(num) in range(11, 20):
        if int(num) == 11:
            numExtenso = "Onze"
        elif int(num) == 11:
            numExtenso = "Doze"
        elif int(num) == 13:
            numExtenso = "Treze"
        elif int(num) == 14:
            numExtenso = "Quatorze"
        elif int(num) == 15:
            numExtenso = "Quinze"
        elif int(num) in range (16, 18):
            numExtenso = "Dezes" + umDigito[int(num) - 10]
        elif int(num) == 18:
            numExtenso = "Dezoito"
        elif int(num) == 19:
            numExtenso = "Dezenove"
    elif int(num) == 20:
        numExtenso = "Vinte"
    elif int(num) in range(21,30):
        numExtenso = "Vinte e " + umDigito[int(num) - 20]
    elif int(num) == 30:
        numExtenso = "Trinta"
    elif int(num) in range(31, 40):
        numExtenso = "Trinta e " + umDigito[int(num) - 30]
    elif int(num) == 40:
        numExtenso = "Quarenta"
    elif int(num) in range(41, 50):
        numExtenso = "Quarenta e " + umDigito[int(num) - 40]
    elif int(num) == 50:
        numExtenso = "Cinquenta"
    elif int(num) in range(51, 60):
        numExtenso = "Cinquenta e " + umDigito[int(num) - 50]
    elif int(num) == 60:
        numExtenso = "Sessenta"
    elif int(num) in range(61, 70):
        numExtenso = "Sessenta e " + umDigito[int(num) - 60]
    elif int(num) == 70:
        numExtenso = "Setenta"
    elif int(num) in range(71, 80):
        numExtenso = "Setenta e " + umDigito[int(num) - 70]
    elif int(num) == 80:
        numExtenso = "Oitenta"
    elif int(num) in range(81, 90):
        numExtenso = "Oitenta e " + umDigito[int(num) - 80]
    elif int(num) == 90:
        numExtenso = "Noventa"
    elif int(num) in range(91, 100):
        numExtenso = "Noventa e " + umDigito[int(num) - 90]
    elif int(num) == 20:
        numExtenso = "Vinte"
    print(numExtenso)