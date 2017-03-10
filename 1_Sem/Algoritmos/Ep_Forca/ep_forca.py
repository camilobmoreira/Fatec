#

def desenha(len_erradas, palav_certa):
    print(forca[len_erradas])
    print(palav_certa)

def win(palav_certa, palavra):
    for letra in palavra:
        if letra not in certas:
            return False
    return True

def again():
    while True:
        resposta = input("Deseja jogar novamente (S/N)?").lower().strip()
        if resposta == "s":
            return True
        elif resposta == "n":
            return False
        else:
            print("Resposta inválida.")
            continue

def chute(letras):
    while True:
        letra = input("Chute uma letra: ").strip().lower()
        if len(letra) != 1: # Verifica se foi jogada apenas uma letra
            print("Informe apenas uma letra.")
            continue

        if not letra.isalpha(): # Verifica se foi digitada uma letra e não um número ou caracter especial
            print("Informe uma letra")
            continue

        if letra in letras: # Verifica se a letra já foi jogada
            print("Letra já escolhida.")
            continue
        return letra

def sorteia():
    arquivo = open("br.txt") #Baixar arquivo novamente

    from random import randint

    for palavra in arquivo.readlines():
        sorteada = palavra
        numero = randint(0, 852)
        if numero == 23:
            arquivo.close()
            return sorteada.lower().strip()


#Inicio do código
#Declaração de variáveis
forca =[
'''
  +-----+
  |     |
        |
        |
        |
        |
=========
''',

'''
  +-----+
  |     |
  O     |
        |
        |
        |
=========
''',

'''
  +-----+
  |     |
  O     |
  |     |
        |
        |
=========
''',

'''
  +-----+
  |     |
  O     |
 /|     |
        |
        |
=========
''',

'''
  +-----+
  |     |
  O     |
 /|\    |
        |
        |
=========
''',

'''
  +-----+
  |     |
  O     |
 /|\    |
 /      |
        |
=========
''',

'''
  +-----+
  |     |
  O     |
 /|\    |
 / \    |
        |
=========
'''
]

certas = ''
erradas = ''
palav_certa = ''

palavra = sorteia()

#Inicio do programa
while True:
    desenha(len(erradas), palav_certa)

    letras = certas + erradas  # Junta as letras certas e erradas em uma única variavel

    letra = chute(letras)  # Pede pro usuário chutar uma letra

    if letra in palavra:  # Verifica se a letra está na palavra
        certas += letra  # Se sim, adiciona na lista de certas
        palav_certa = ''
        for cada_letra in palavra:
            if cada_letra in certas:
                palav_certa += cada_letra
            else:
                palav_certa += '_'
        print("Você acertou uma letra.")
    else:
        erradas += letra  # Se não, adiciona na lista de erradas
        print("Letra não existente na palavra.")

    if win(palav_certa, palavra): #Criar
        print("Você ganhou. Parabéns. A palavra é %s" %palavra)
        if again():
            erradas = ''
            certas = ''
            palav_certa = ''
            palavra = sorteia()
            continue
        else:
            break

    if len(erradas) >= 7:
        print("Você perdeu. A palavra certa era %s" % palavra)
        if again():
            erradas = ''
            certas = ''
            palav_certa = ''
            palavra = sorteia()
            continue
        else:
            break

