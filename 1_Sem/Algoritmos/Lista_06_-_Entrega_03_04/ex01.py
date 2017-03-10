jose = 0
joao = 0
tadeu = 0
maria = 0
nulo = 0
branco = 0
voto = 0
total = 0
while voto == 0 or voto == 1 or voto == 2 or voto == 3 or voto == 4 or voto == 5 or voto == 6:
    voto = int(input("Informe o seu voto: \n1 - José; \n2 - João; \n3 - Tadeu; \n4 - Maria; \n5 - Voto Nulo; \n6 - Voto em Branco.\n"))

    if voto == 1:
        jose += 1
    elif voto == 2:
        joao += 1
    elif voto == 3:
        tadeu += 1
    elif voto == 4:
        maria += 1
    elif voto == 5:
        nulo += 1
    elif voto == 6:
        branco += 1
    elif voto ==0:
        break
    else:
        print("Opção inválida.")
    total += 1

porc_nulo = (nulo*100)/total
porc_branco = (branco*100)/total
print("Resultado final: \nJosé = %i; \nJoão = %i; \nTadeu = %i; \nMaria = %i; \nNulo = %i; \nPorcentagem de votos nulos = %.1f \nBranco = %i; \nPorcentagem de votos brancos = %.1f." %(jose, joao, tadeu, maria, nulo, porc_nulo, branco, porc_branco))


