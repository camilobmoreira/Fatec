exp = ""
while True:
    exp = input("Entre com uma expressão com parenteses: ")
    if "(" in exp or ")" in exp:
        break

qtdPA = exp.count("(")
qtdPF = exp.count(")")
if qtdPA == qtdPF:
    print("%s OK!" %exp)
else:
    print("%s Erro!" % exp)
