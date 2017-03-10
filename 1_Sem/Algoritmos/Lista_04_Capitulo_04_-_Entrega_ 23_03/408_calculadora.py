#4.8) Escreva um programa que leia dois números e que pergunte qual operação você deseja realizar. Você deve poder calcular a soma (+), a subtração (-), multiplicação (*) e divisão (/). Exiba o resultado da operação solicitada.

a = float(input("Informe o primeiro número: "))
b = float(input("Informe o segundo número: "))

while(True):
	op = input("Informe o número ou o simbolo da operação desejada: \n1 - soma (+); \n2 - subtração (-); \n3 - multiplicação (*); \n4 - divisão (/). \n")

	if(op == "1" or op == "+"):
		print("O resultado da conta %.1f + %.1f é: %.1f" %(a, b, a + b))
		break
	elif(op == "2" or op == "-"):
		print("O resultado da conta %.1f - %.1f é: %.1f" %(a, b, a - b))
		break
	elif(op == "3" or op == "*"):
		print("O resultado da conta %.1f * %.1f é: %.1f" %(a, b, a * b))
		break
	elif(op == "4" or op == "/"):
		print("O resultado da conta %.1f / %.1f é: %.1f" %(a, b, a / b))
		break
	else:
		print("Operação inválida.")

