num1 = int(input("Entre com o dividendo: "))
num2 = int(input("Entre com o divisor: "))
x = 0
divisao = num1
resto = 0
result = 0
while(divisao > 0):
    if(divisao > num2):
        divisao -= num2
        result += 1
    else:
        resto = divisao
        divisao -= divisao
print("Divisao: %i \nResto: %i" %(result, resto))