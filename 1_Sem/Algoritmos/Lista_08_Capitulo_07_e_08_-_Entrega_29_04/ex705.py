#

frase1 = input("Informe a frase 1: ").lower().strip()
frase2 = input("Informe a frase 2: ").lower().strip()
frase3 = ""

for letra in frase1:
    if letra not in frase2:
        frase3 += letra
print(frase3)