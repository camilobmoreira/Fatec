#

def leArquivo(nomeArquivo):
    dicEstudantes = []
    arquivo = open(nomeArquivo)
    estudante = {}
    for linha in arquivo.readlines():
        if linha.strip() == "#":
            dicEstudantes.append(estudante)
            estudante = {}
            continue
        dados = linha.strip().split(":")
        id = dados[0].strip()
        valores = dados[1].strip()

        if id == "nome": estudante["nome"] = valores

        lstValores = []
        for valor in valores.split(","):
            if valor.isalpha(): continue
            valorTemp = str(int(float(valor)))
            if valorTemp.isdigit():lstValores.append(float(valor))

        if id == "deveres": estudante["dever de casa"] = lstValores
        if id == "quizzes": estudante["quizzes"] = lstValores
        if id == "testes": estudante["testes"] = lstValores

    arquivo.close()
    return dicEstudantes

def detail(estudante):
    print(estudante["nome"])
    print(estudante["dever de casa"])
    print(estudante["quizzes"])
    print(estudante["testes"])

def mediaSimples(listaNotas):
    media = sum(listaNotas) / len(listaNotas)
    return media

def getAverage(registroEstudante):
    mediaPonderada = 0
    mediaPonderada += mediaSimples(registroEstudante["dever de casa"]) * .1
    mediaPonderada += mediaSimples(registroEstudante["quizzes"]) * .3
    mediaPonderada += mediaSimples(registroEstudante["testes"]) * .6
    return mediaPonderada

def getLetterGrade(pontuacao):
    if pontuacao >= 90: return "A"
    elif pontuacao >= 80: return "B"
    elif pontuacao >= 70: return "C"
    elif pontuacao  >= 60: return "D"
    else: return "F"

def getClassAverage(dicEstudantes):
    mediaSala = 0
    for estudante in dicEstudantes:
        detail(estudante)
        print("Nota final: %.2f" %getAverage(estudante))
        print("Conceito final: %s" %getLetterGrade(getAverage(estudante)))
        mediaSala += mediaSimples(estudante["dever de casa"] + estudante["quizzes"] + estudante["testes"])
        print()
    print("Média simples da sala: %.2f" %(mediaSala / len(dicEstudantes)))

dicEstudantes = leArquivo("dados.txt")

getClassAverage(dicEstudantes)