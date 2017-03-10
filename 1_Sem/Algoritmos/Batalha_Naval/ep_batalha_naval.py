#

def errorValidation():
    saida = open("resultado.txt", "w")
    saida.write("ERROR_VALIDATION")
    saida.close()

def errorInvalidCoordinate():
    saida = open("resultado.txt", "w")
    saida.write("ERROR_INVALID_COORDINATE")
    saida.close()

def errorInvalidInputFile():
    saida = open("resultado.txt", "w")
    saida.write("ERROR_INVALID_INPUT_FILE")
    saida.close()

def imprimeResultado(idGanhador, acertosParciais, acertosTotais, restanteParciais, restanteTotais, pontuacao):
    saida = open("resultado.txt", "w")
    saida.write('''%s %iP %iT %iP %iT %i
ID_GANHADOR ACERTOS_PARCIAIS ACERTOS_TOTAIS REST_PARCIAIS REST_TOTAIS PONTUACAO''' %(
        idGanhador, acertosParciais, acertosTotais, restanteParciais, restanteTotais, pontuacao))
    saida.close()

def validaPosicaoLetra(posicaoLetra):
    if posicaoLetra.isalpha() and posicaoLetra in "ABCDEFGHIJLMNOP": return True
    errorValidation()
    return False

def validaPosicaoNumero(posicaoNumero):
    if posicaoNumero.isdigit() and int(posicaoNumero) > 0 and int(posicaoNumero) < 16: return True
    errorValidation()
    return False

def validaDirecaoNavio(direcaoNavio):
    if direcaoNavio in "HV": return True
    errorValidation()
    return False

def validaTorpedo(posicao):
    if posicao[0].isalpha() and posicao[0] in "ABCDEFGHIJLMNOP": return True
    if len(posicao) == 3:
        if validaPosicaoNumero(posicao[1] + posicao[2]) in range(1, 16): return True
    elif int(posicao[1]) == 0 or not posicao[1].isdigit(): return True
    errorInvalidCoordinate()
    return False

def leTorpedo(torpedos):
    torpedos = torpedos.strip().split(";")[1]
    torpedos = torpedos.strip().split("|")
    if len(torpedos) != 20 or torpedos[-1] == '': errorValidation()
    for posicao in torpedos:
        if not validaTorpedo(posicao): return False
    return torpedos

def validaNavio(n, navio):
    for x in navio:
        for y in n:
            if y in x:
                errorInvalidInputFile()
                return False
    return True

def validaQtdeNavios(codigo, posicoes):
    posicao = posicoes.split("|")
    if codigo == 1 or codigo == 2:
        if len(posicao) == 2: return True
    if codigo == 3:
        if len(posicao) == 5: return True
    if codigo == 4:
        if len(posicao) == 4: return True
    errorValidation()
    return False

def posicionaNavio(codigo, posicaoLetra, posicaoNum, direcao):
    navio = []
    posicoesVerticais1 = {"A": 1, "B": 2, "C": 3, "D": 4, "E": 5, "F": 6, "G": 7, "H": 8, "I": 9, "J": 10, "L": 11,
                          "M": 12, "N": 13, "O": 14, "P": 15}
    posicoesVerticais2 = {"1": "A", "2": "B", "3": "C", "4": "D", "5": "E", "6": "F", "7": "G", "8": "H", "9": "I",
                          "10": "J", "11": "L", "12": "M", "13": "N", "14": "O", "15": "P"}
    if codigo == 3:
        navio.append(posicaoLetra + posicaoNum)
    elif direcao == "H":
        posicaoNum = int(posicaoNum)
        if codigo == 1:
            navio.append(posicaoLetra + str(posicaoNum))
            navio.append(posicaoLetra + str(posicaoNum + 1))
            navio.append(posicaoLetra + str(posicaoNum + 2))
            navio.append(posicaoLetra + str(posicaoNum + 3))
        elif codigo == 2:
            navio.append(posicaoLetra + str(posicaoNum))
            navio.append(posicaoLetra + str(posicaoNum + 1))
            navio.append(posicaoLetra + str(posicaoNum + 2))
            navio.append(posicaoLetra + str(posicaoNum + 3))
            navio.append(posicaoLetra + str(posicaoNum + 4))
        elif codigo == 4:
            navio.append(posicaoLetra + str(posicaoNum))
            navio.append(posicaoLetra + str(posicaoNum + 1))
    elif direcao == "V":
        posV = posicoesVerticais1[posicaoLetra]
        if codigo == 1:
            navio.append(posicoesVerticais2[str(int(posV))] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 1)] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 2)] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 3)] + posicaoNum)
        elif codigo == 2:
            navio.append(posicoesVerticais2[str(int(posV))] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 1)] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 2)] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 3)] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 4)] + posicaoNum)
        elif codigo == 4:
            navio.append(posicoesVerticais2[str(int(posV))] + posicaoNum)
            navio.append(posicoesVerticais2[str(int(posV) + 1)] + posicaoNum)
    return navio

def leNavios(navios):
    navio = []
    if ";" in navios:
        dados = navios.strip().split("\n")
        for linha in dados:
            linha = linha.strip().split(";")
            codigo = int(linha[0])
            posicoes = linha[1]
            if not validaQtdeNavios(codigo, posicoes): return False
            if "|" in posicoes:
                for posicao in posicoes.split("|"):
                    posicaoLetra, posicaoNum, direcao = '','',''
                    if len(posicao) >= 3:
                        if posicao[2].isdigit():
                            if not validaPosicaoNumero(posicao[1] + posicao[2]): return False
                            posicaoNum = posicao[1] + posicao[2]
                            if len(posicao) == 4:
                                if not validaDirecaoNavio(posicao[3]): return False
                                direcao = posicao[3]
                        else:
                            if not validaPosicaoLetra(posicao[0]) or not validaDirecaoNavio(posicao[2]): return False
                            posicaoNum = posicao[1]
                            direcao = posicao[2]
                    else:
                        if not validaPosicaoNumero(posicao[1]): return False
                        posicaoNum = posicao[1]
                    posicaoLetra = posicao[0]
                    n = posicionaNavio(codigo, posicaoLetra, posicaoNum, direcao)
                    if not validaNavio(n, navio): return False
                    navio.append(n)
    return navio

def leArquivo(nomeArquivo):
    entrada = open(nomeArquivo)
    dados = entrada.read().strip().split("# Jogada")
    navios = dados[0]
    torpedos = dados[1]
    navios = leNavios(navios)
    torpedos = leTorpedo(torpedos)
    entrada.close()
    dicDados = {}
    dicDados["navios"] = navios
    dicDados["torpedos"] = torpedos
    return dicDados

def batalha(j1, j2):
    #Jogador 1
    pontosJ1 = 0
    acertosParciaisJ1 = 0
    acertosTotaisJ1 = 0
    restanteParciasJ2 = 0
    restanteTotaisJ2 = len(j2["navios"])
    for navio in j2["navios"]:
        acertos = 0
        for torpedo in j1["torpedos"]:
            if torpedo in navio:
                acertos += 1
                pontosJ1 += 3
                acertosParciaisJ1 += 1
                restanteTotaisJ2 -= 1
        if acertos >= 1: restanteParciasJ2 += 1
        if len(navio) == acertos:
            pontosJ1 += 2
            acertosTotaisJ1 += 1
            acertosParciaisJ1 -= acertos #CASO ACERTOS TOTAIS NAO CONTEM NOS ACERTOS PARCIAIS
            restanteParciasJ2 -= 1

    #Jogador 2
    pontosJ2 = 0
    acertosParciaisJ2 = 0
    acertosTotaisJ2 = 0
    restanteParciasJ1 = 0
    restanteTotaisJ1 = len(j1["navios"])
    for navio in j1["navios"]:
        acertos = 0
        for torpedo in j2["torpedos"]:
            if torpedo in navio:
                acertos += 1
                pontosJ2 += 3
                acertosParciaisJ2 += 1
                restanteTotaisJ1 -= 1
        if acertos >= 1: restanteParciasJ1 += 1
        if len(navio) == acertos:
            pontosJ2 += 2
            acertosTotaisJ2 += 1
            acertosParciaisJ2 -= acertos #CASO ACERTOS TOTAIS NAO CONTEM NOS ACERTOS PARCIAIS
            restanteParciasJ1 -= 1

    if pontosJ1 > pontosJ2: imprimeResultado("J1", acertosParciaisJ1, acertosTotaisJ1, restanteParciasJ2, restanteTotaisJ2, pontosJ1)
    elif pontosJ2 > pontosJ1: imprimeResultado("J2", acertosParciaisJ2, acertosTotaisJ2, restanteParciasJ1, restanteTotaisJ1, pontosJ2)
    else:
        saida = open("resultado.txt", "w")
        saida.write('''%s %iP %iT %iP %iT %i
ID_GANHADOR ACERTOS_PARCIAIS ACERTOS_TOTAIS REST_PARCIAIS REST_TOTAIS PONTUACAO
%s %iP %iT %iP %iT %i
ID_GANHADOR ACERTOS_PARCIAIS ACERTOS_TOTAIS REST_PARCIAIS REST_TOTAIS PONTUACAO''' % (
        "J1", acertosParciaisJ1, acertosTotaisJ1, restanteParciasJ2, restanteTotaisJ2, pontosJ1, "J2",
        acertosParciaisJ2, acertosTotaisJ2, restanteParciasJ1, restanteTotaisJ1, pontosJ2
        ))
        saida.close()

j1 = leArquivo("jogador1.txt")
j2 = leArquivo("jogador2.txt")
batalha(j1, j2)