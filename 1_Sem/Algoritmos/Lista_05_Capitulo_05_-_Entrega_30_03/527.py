num = int(input("Entre com um número: "))
num = str(num)
x = 0
palind = ''
while x <= len(num)-1:
    palind = num[x] + palind #Inverter o número. Mudar o último digito para o começo.
    x += 1
if(num == palind):
    print("É um palindromo.")
else:
    print("Não é um palindromo.")