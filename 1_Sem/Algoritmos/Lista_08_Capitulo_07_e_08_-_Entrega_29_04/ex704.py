#

frase = input("Informe uma frase: ").lower()
letraComputada = ""

for letra in frase:
    if letra not in letraComputada:
        print("A letra \'%s\' aparece %i vezes na frase \'%s\'." %(letra, frase.count(letra), frase))
        letraComputada += letra