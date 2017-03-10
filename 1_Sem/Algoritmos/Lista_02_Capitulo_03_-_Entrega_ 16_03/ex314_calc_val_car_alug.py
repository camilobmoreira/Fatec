#Calcula valor do carro alugado
km = float(input("Quantos km foram rodados com o carro? \n"))
dias = int(input("Quantos dias ficou com o carro? \n"))
conta = (km * 0.15) + (dias * 60) #Calcula quanto irá pagar
print("Você irá pagar R$%.2f pelo aluguel do carro" %conta)
