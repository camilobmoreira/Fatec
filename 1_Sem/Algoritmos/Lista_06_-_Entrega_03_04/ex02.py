veiculos = [
    [1, "Ká", 15],
    [2, "Uno", 14.4],
    [3, "Pálio", 12.3],
    [4, "Astra", 10.1],
    [5, "Fox", 11.5]
]

x = 0
while x <= 4:
    print("Veículo %i; \nModelo: %s; \nKm por litro: %.1f. \n" %(veiculos[x][0], veiculos[x][1], veiculos[x][2]))
    x += 1

x = 0
print("Relatório final:")
while x <= 4:
    print("%i - %s - %.1f - %.1f litros - R$%.2f" %(veiculos[x][0], veiculos[x][1], veiculos[x][2], (1000 / veiculos[x][2]), ((1000 / veiculos[x][2]) * 2.25) ))
    x += 1

eco = []
x = 1
while x <= 4:
    if (veiculos[0][2] > veiculos[x][2]):
        eco = veiculos[0]
    elif (veiculos[x][2] > veiculos[0][2]):
        eco = veiculos[x]
    x += 1
print("O menor consumo é o do %s" %eco[1])