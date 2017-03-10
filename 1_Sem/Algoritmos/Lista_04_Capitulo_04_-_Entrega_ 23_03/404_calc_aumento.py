#Calcula aumento de salário
sal = float(input("Informe o salário: "))
if(sal > 1250):
	print("O aumento deverá ser de R$%.2f no salário informado" %(sal * .1))
else:
	print("O aumento deverá ser de R$%.2f no salário informado" %(sal * .15))
