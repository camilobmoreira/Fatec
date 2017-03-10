lista1 = []
lista2 = []
lista3 = []
a = ""

x = 1
while x <= 3:
    a = input("Entre com o %iº elemento da 1ª lista: " %(x))
    lista1.append(a)
    x +=1
print("Lista 1 = %s" %lista1)

x = 1
while x <= 3:
    a = input("Entre com o %iº elemento da 2ª lista: " %(x))
    lista2.append(a)
    x +=1
print("Lista 2 = %s" %lista2)

lista12 = lista1 + lista2

x = 0
while x < len(lista12):
    a = lista12[x]
    if a not in lista3:
        lista3.append(a)
    x += 1

print("Lista 3 = %s" %lista3)