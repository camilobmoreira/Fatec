#

frase1 = input("Informe a frase 1: ").lower()
frase2 = input("Informe a frase 2: ").lower()

if frase2 in frase1:
    print("A frase \'%s\' foi encontrada na posição %i na frase \'%s\'" %(frase2, frase1.find(frase2), frase1))
else:
    print("Frase \'%s\' não encontrada na frase \'%s\'" %(frase2, frase1))