#4.9) Escreva um programa para aprovar o empréstimo bancário para compra de uma casa. O programa deve perguntar o valor da casa a comprar, o salário e a quantidade de anos a pagar. O valor da prestação mensal não pode ser superior a 30% do salário. Calcule o valor da prestação como sendo o valor da casa a comprar dividido pelo número de meses a pagar.

val = -1
while(val < 0):
	val = float(input("Informe o valor do imóvel: "))
	if(val < 0):
		print("Informe um valor válido.")
sal = -1
while(sal < 0):
	sal = float(input("Informe o salário: "))
	if(sal < 0):
		print("Informe um salário válido.")
anos = -1
while(anos < 0):
	anos = float(input("Informe a quantidade de anos a pagar "))
	if(anos < 0):
		print("Informe uma quantidade em anos válida.")

meses = anos * 12
prest = val / meses
if(prest < (sal * .3)):
	print("Empréstimo aprovado. \nA prestação de R$%.2f será paga durante %.0f meses" %(prest, meses))
elif(prest > (sal * .3)):
	print("Não é possível fazer o empréstimo. O valor da prestação não pode ser superior a 30% do salário.")


