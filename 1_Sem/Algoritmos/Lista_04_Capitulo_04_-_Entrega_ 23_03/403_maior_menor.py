#Mostra o maior e o menor numero entre tres numeros.
a = int(input("Infome o primeiro número: "))
b = int(input("Informe o segundo número: "))
c = int(input("Informe o terceiro número: "))

if (a > b and a > c):
	print("O número %i (primeiro digitado) é o maior número." %a)
elif (b > a and b > c):
	print("O número %i (segundo digitado) é o maior número." %b)
elif (c > a and c > b):
	print("O número %i (terceiro digitado) é o maior número." %c)

if (a < b and a < c):
	print("O número %i (primeiro digitado) é o menor número." %a)
elif (b < a and b < c):
	print("O número %i (segundo digitado) é o menor número." %b)
elif (c < a and c < b):
	print("O número %i (terceiro digitado) é o menor número." %c)

if (a == b and a == c):
	print("Todos os números digitados são iguais.")
