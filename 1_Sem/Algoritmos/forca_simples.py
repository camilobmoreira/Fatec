listaPalavras = ["satelite", "mustang", "guaxinim", "navio", 'doutor']

from random import randint
var = randint(0, 4)

palavra = str(listaPalavras[var])
palavraList = list(palavra)
palavEmBranco = []

while len(palavEmBranco) < len(palavraList):
    palavEmBranco.append("_")

print("A palavra tem %i letras" %len(palavEmBranco))

tentativas = 6

while tentativas >= 0:
    print(palavEmBranco)
    letra = input("Tente uma letra: ").lower().strip()

    if len(letra) > 1:
        print("Tentando a palavra inteira...")
        if letra == palavra:
            print("Parabéns, você acertou a palavra!")
            break
        else:
            print("Tente novamente. A palavra correta é %s." % palavra)
            break

    x = 0
    while x < len(palavEmBranco):
        if letra == palavraList[x]:
            print("Você acerteou uma letra.")
            palavEmBranco[x] = palavraList[x]
        if x == len(palavEmBranco)-1 and letra not in palavraList:
            print("A palavra não possui a letra %s" %letra)
        x += 1

    if tentativas == 1:
        print("Essa é sua última tentativa.")
        letra = input("Tente a palavra: ").lower()
        if letra == palavra:
            print("Parabéns, você acertou a palavra!")
            break
        else:
            print("Tente novamente. A palavra correta é %s." %palavra)
            break

    tentativas -= 1