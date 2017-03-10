#

frase1 = input("Informe a frase 1: ").lower()
frase2 = input("Informe a frase 2: ").lower()
frase3 = ""

for letra in frase1:
    if letra == " ":
        continue
    if letra in frase2:
        frase3 += letra
frase3 = list(frase3)
frase3 = "".join(frase3)
print(frase3)
