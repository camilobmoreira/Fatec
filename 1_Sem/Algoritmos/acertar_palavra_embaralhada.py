listaPalavras = ["doutor", "chapeu", "navio", "livro", "idolo", "principe", "toalha", "piano", "estrela", "padrinho"]

import random
var = random.randint(0, 4)

palavra = str(listaPalavras[var])
palavraEmbaralhada = list(palavra)
random.shuffle(palavraEmbaralhada)
palavraEmbaralhada = "".join(palavraEmbaralhada)

tentativas = 6

while tentativas > 0:
    print("A palavra embaralhada é %s" %(palavraEmbaralhada))
    print("Você tem %i chances." %tentativas)
    palavraT = input("Tente advinhar a palavra: ").lower().strip()

    if palavraT == palavra:
        print("Parabéns, você acertou a palavra!")
        break
    else:
        print("Tente novamente.")
        print("\n")

    tentativas -= 1

    if tentativas == 0:
        print("Você errou. A palavra correta é %s." % palavra)
        break