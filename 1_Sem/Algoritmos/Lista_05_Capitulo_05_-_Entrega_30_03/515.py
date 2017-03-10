preco = 0
while(True):
    codProd = int(input("Informe o código do produto: "))
    if codProd == 1:
        qtde = int(input("Informe a quantidade comprada: "))
        preco += qtde * .5
    elif codProd == 2:
        qtde = int(input("Informe a quantidade comprada: "))
        preco += qtde * 1
    elif codProd == 3:
        qtde = int(input("Informe a quantidade comprada: "))
        preco += qtde * 4
    elif codProd == 5:
        qtde = int(input("Informe a quantidade comprada: "))
        preco += qtde * 7
    elif codProd == 9:
        qtde = int(input("Informe a quantidade comprada: "))
        preco += qtde * 8
    elif codProd == 0:
        break
    else:
        print("Código inválido.")
print("Preço final: R$%.2f" %preco)
