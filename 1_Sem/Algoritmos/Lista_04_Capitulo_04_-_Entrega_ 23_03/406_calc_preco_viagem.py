#4.6) Escreva um programa que pergunte a distância que um passageiro deseja percorrer em km. Calcule o preço da passagem, cobrando R$0,50 por km para viagens de até 200km e R$0,45 para viagens mais longas.

dist = -5
while(dist < 0):
	dist = float(input("Informe a distância da viagem (km): "))
	if(dist < 0):
		print("Informe um valor maior que zero.")
if(dist <= 200):
	print("A passagem ficou em R$%.2f" %(dist * .5))
elif(dist > 200):
	print("A passagem ficou em R$%.2f" %(dist * .45))
