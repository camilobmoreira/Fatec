#

def leCPF():
    while True:
        cpf = input("Informe o CPF: ")
        if len(cpf) == 9:
            return cpf
        elif len(cpf) == 11:
            return cpf
        else:
            print("CPF inválido.")
            continue

def gerarNumeroControleCPF(cpf):
    s = 0
    if len(cpf) != 9:
        print("CPF inválido para essa função.")
        print("CPF deve ter 9 dígitos.")
        return False

    #Calcular 10º digito
    decDigito = 0
    for i in range(1, 10): s += int(cpf[i - 1]) * i
    if s % 11 != 10: decDigito = s % 11


    # Calcular 11º digito
    decPDigito = 0
    s = 0
    cpf += str(decDigito)
    for i in range(10): s += int(cpf[i]) * i
    if s % 11 != 10: decPDigito = s % 11

    cpf += str(decPDigito)

    digitosControle = str(decDigito) + str(decPDigito)
    return cpf, digitosControle

def validaCPF(cpf):
    if len(cpf) != 11:
        print("CPF inválido para essa função.")
        print("CPF deve ter 11 dígitos.")
        return False

    dados = gerarNumeroControleCPF(cpf[0:9])
    cpfGerado = dados[0]
    if cpf == cpfGerado: return True
    else: return False




while True:
    opcao = int(input("Escolha a opção desejada: \n1 - Calcular os dígitos de controle do CPF; \n2 - Verificar a validade de um CPF; \n0 - Sair \n"))
    if opcao == 1:
        dados = gerarNumeroControleCPF(leCPF())
        print("CPF gerado: %s;\nDigitos de controle: %s." %(dados[0], dados[1]))
        break
    elif opcao == 2:
        print(validaCPF(leCPF()))
        break
    elif opcao == 0:
        print("Saindo...")
        break
    else:
        print("Opção inválida.")
        continue
