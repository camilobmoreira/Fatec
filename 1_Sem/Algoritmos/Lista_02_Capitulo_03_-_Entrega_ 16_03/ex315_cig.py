#Calcula a redução no tempo de vida de um fumante
cig_dia = int(input("Quantos cigarros você fuma por dia? \n"))
anos = float(input("Há quantos anos você fuma? \n"))
dias_perdidos = cig_dia * (365 * anos) * 10 / 6 * 24
print("Você perdeu cerca de %.1f dias na sua expectativa de vida devido ao cigarro" %dias_perdidos)
