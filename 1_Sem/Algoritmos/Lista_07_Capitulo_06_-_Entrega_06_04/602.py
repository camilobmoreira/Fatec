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

x = 0
while x < len(lista1):
    lista3.append(lista1[x])
    x += 1
x = 0
while x < len(lista2):
    lista3.append(lista2[x])
    x += 1
print("Lista 3 = %s" %lista3)