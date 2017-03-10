#

frase1 = input("Informe a frase 1: ").lower().strip()
frase2 = input("Informe a frase 2: ").lower().strip()
frase3 = input("Informe a frase 2: ").lower().strip()

for indice in range(len(frase2)):
    frase1 = frase1.replace(frase2[indice], frase3[indice])
print(frase1)