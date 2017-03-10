#Calcula valor da conta eletrica

kwh = -1
while(kwh < 0):
	kwh = float(input("Informe a quantidade de kWh consumida: "))
	if(kwh < 0):
		print("Informe um valor válido.")
tipo = " "
while(tipo != "R" and tipo != "C" and tipo != "I"):
	tipo = input("Informe o tipo de instalação: \nR - Residencial; \nC - Comercial; \nI - Industrial. \n").upper()
	if(tipo != "R" and tipo != "C" and tipo != "I"):
		print("Informe um valor válido.")

if(tipo == "R"):
	if(kwh <= 500):
		print("O valor da conta é R$%.2f" %(kwh * .4))
	elif(kwh > 500):
		print("O valor da conta é R$%.2f" %(kwh * .65))
elif(tipo == "C"):
	if(kwh <= 1000):
		print("O valor da conta é R$%.2f" %(kwh * .55))
	elif(kwh > 1000):
		print("O valor da conta é R$%.2f" %(kwh * .6))
elif(tipo == "I"):
	if(kwh <= 5000):
		print("O valor da conta é R$%.2f" %(kwh * .55))
	elif(kwh > 5000):
		print("O valor da conta é R$%.2f" %(kwh * .6))
