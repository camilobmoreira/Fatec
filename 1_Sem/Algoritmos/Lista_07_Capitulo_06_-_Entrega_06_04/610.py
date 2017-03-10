l = [15, 7, 27, 39, 15, 7, 7, 15, 10, 6, 27, 0]
p = int(input("Digite o valor a procurar: "))
v = int(input("Digite outro valor a procurar: "))
achouP = False
achouV = False
posiP = []
x = 0
while x < len(l):
    if l[x] == p:
        achouP = True
        posiP.append(x)
    x += 1
if achouP:
    print("%i achado na(s) posição(ões) %s" %(p, posiP))
else:
    print("%i não encontrado" %p)

posiV = []
x = 0
while x < len(l):
    if l[x] == v:
        achouV = True
        posiV.append(x)
    x += 1
if achouV:
    print("%i achado na(s) posição(ões) %s" % (v, posiV))
else:
    print("%i não encontrado" %p)