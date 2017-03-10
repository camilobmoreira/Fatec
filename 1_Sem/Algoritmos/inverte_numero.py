num = int(input("Entre com um número: "))
num = str(num)
x = 0
palind = ''
while x <= len(num)-1:
    palind = num[x] + palind #Inverter o número. Mudar o último digito para o começo.
    x += 1
print("O número %s invertido é %s" %(num, palind))