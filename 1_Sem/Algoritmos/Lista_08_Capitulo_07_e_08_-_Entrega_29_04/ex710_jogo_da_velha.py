#

tabuleiro = [
    ["1", "2", "3"],
    ["4", "5", "6"],
    ["7", "8", "9"]
]

print("Use os números para escolher a posição em que jogará: ")

jog1 = True
jogadasJog1 = ""
jog2 = False
jogadasJog2 = ""
gameOver = False
vencedor = ""
posibilidades = ["123", "456", "789", "147", "258", "369", "159", "357"]

while True:
    tabuleiroString = ""
    for linha in tabuleiro:
        tabuleiroString += "".join(linha)
    if tabuleiroString.count("X") >= 3 or tabuleiroString.count("O") >= 3:
        jogadasJog1 = list(jogadasJog1)
        jogadasJog1.sort()
        jogadasJog1 = "".join(jogadasJog1)

        jogadasJog2 = list(jogadasJog2)
        jogadasJog2.sort()
        jogadasJog2 = "".join(jogadasJog2)

        for byte in posibilidades:
            if byte in jogadasJog1:
                vencedor = "jogador 1"
                jog1 = False
                jog2 = False
                gameOver = True
                break
            elif byte in jogadasJog2:
                vencedor = "jogador 2"
                jog1 = False
                jog2 = False
                gameOver = True
                break
        if gameOver:
            for x in range(100):
                print()
            print("O vencedor foi o %s \n" %vencedor)
            for linha in tabuleiro:
                print("%s | %s | %s" % (linha[0], linha[1], linha[2]))
                if linha != tabuleiro[2]:
                    print("--+---+--")
            break

    if jog1:
        for linha in tabuleiro:
            print("%s | %s | %s" % (linha[0], linha[1], linha[2]))
            if linha != tabuleiro[2]:
                print("--+---+--")
        pos = input("Vez do jogador 1 (O). Escolha a posição: ")
        if int(pos) in range(1,10):
            if pos in tabuleiroString:
                for indiceLinha in range(3):
                    for indiceColuna in range(3):
                        if tabuleiro[indiceLinha][indiceColuna] == pos:
                            tabuleiro[indiceLinha][indiceColuna] = "O"
                            jogadasJog1 += pos
                            jog1 = False
                            jog2 = True

            else:
                print("Posição já ocupada.")
                continue
        else:
            print("Posição inválida.")
            continue

    elif jog2:
        for linha in tabuleiro:
            print("%s | %s | %s" % (linha[0], linha[1], linha[2]))
            if linha != tabuleiro[2]:
                print("--+---+--")
        pos = input("Vez do jogador 2 (X). Escolha a posição: ")
        if int(pos) in range(1, 10):
            if pos in tabuleiroString:
                for indiceLinha in range(3):
                    for indiceColuna in range(3):
                        if tabuleiro[indiceLinha][indiceColuna] == pos:
                            tabuleiro[indiceLinha][indiceColuna] = "X"
                            jogadasJog2 += pos
                            jog1 = True
                            jog2 = False

            else:
                print("Posição já ocupada.")
                continue
        else:
            print("Posição inválida.")
            continue