divi = float(input("Divida: "))
juros = float(input("Juros: "))
pag = float(input("Pagamento mensal: "))
total = divi
if juros < 10:
    juros = juros * .01
elif juros > 10 and juros < 100:
    juros = juros * .1
x = 0
jurosT = total
diviIni = divi
while divi > 0:
    divi = divi + (divi * juros) - pag
    total = total + (total * juros)
    x += 1
jurosT = total - diviIni
print("Meses para pagar a divida: %i \nTotal pago: R$%.2f \nTotal de juros pago: R$%.2f" %(x, total, jurosT))