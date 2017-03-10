atual = 1
anterior = 0
soma = 0
soma_par = 0
soma_impar = 0
soma_quad = 0
indice = 0
print(" %i" %anterior)
while(soma <= 4000):
    c = atual
    print(" %i" %atual)
    atual = atual + anterior
    anterior = c
    soma += atual
    indice += 1
    if(indice % 2 == 0):
        soma_par += atual
    else:
        soma_impar += atual
    soma_quad = (atual**2)
print("Soma = %i; \nSoma indices pares = %i; \nSoma indices impares = %i; \nSoma dos quadrados dos termos = %i." %(soma, soma_par, soma_impar, soma_quad))
