#

import random

n = random.randint(1, 10)
tentativas = 3
tentados = []
while tentativas > 0:
    x = int(input("Escolha um numero entre 1 e 10: "))
    if x in tentados:
        print("Você já tentou esse numero.")
        continue
    tentados.append(x)
    if x == n:
        print("Você acertou!")
        break
    else:
        tentativas -= 1
        if tentativas == 0:
            print("Acabaram suas chances. O número era %i." %n)
            break
        print("Você errou. Você ainda tem %i tentativas." %tentativas)
