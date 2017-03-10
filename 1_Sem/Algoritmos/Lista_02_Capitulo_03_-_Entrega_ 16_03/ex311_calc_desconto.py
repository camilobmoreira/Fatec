#Recebe o preço e o desconto e calcula o desconto
preco = float(input("Informe o valor da mercadoria \n"))
desc = float(input("Informe a porcentagem do desconto \n"))
desconto = desc * 0.01 #Transforma o valor digitado em 0.0[valor_digitado]
preco_final = preco - (preco * desconto)
print("O valor inicial foi R$%.2f. \nO valor com o desconto é de R$%.2f. \nO valor do desconto foi de %.1f%%" %(preco, preco_final, desc)) 
