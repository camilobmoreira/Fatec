#Calcula multa caso velocidade > 80kmh
vel = -5
while(vel < 0):
	vel = float(input("Velocidade do veículo (km/h): "))
	if(vel < 0):
		print("Por favor, digite um valor maior que zero")
	if(vel > 80):
		multa = (vel - 80) * 5
		print("Você foi multado por excesso de velocidade, no valor de R$%.2f" %multa)
