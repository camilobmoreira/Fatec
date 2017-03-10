dep = float(input("Deposito: "))
juros = float(input("Juros: "))
total = dep
if juros < 10:
    juros = juros * .01
elif juros > 10 and juros < 100:
    juros = juros * .1
x = 1
while x < 24:
    dep = float(input("Deposito para o %iº mês : " %x))
    total += dep
    print("Até o mês %i você já tem um total de R$%.2f" %(x, total))
    total += (dep * juros)
    x += 1
print("O total ganho ao final do %iª mês foi R$%.2f" %(x, total))