#Calcula o aumento do salario apos receber a porcentagem do aumento e o salario
sal = float(input("Informe o salário \n"))
aumento = float(input("Informa a porcentagem do aumento \n"))
aumento = aumento * .01 #Transforma o valor digitado em 0.0[valor_digitado] para calcular a porcentagem
sal_final = sal + (sal * aumento)
print("O salário final é R$%.2f" %sal_final)
