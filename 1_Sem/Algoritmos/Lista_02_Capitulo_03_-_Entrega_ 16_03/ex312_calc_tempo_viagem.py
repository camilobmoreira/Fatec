#Calcula o tempo baseado na distancia e velocidade média
dist = float(input("Qual a distância da viagem? \n"))
vel = float(input("Qual a velocidade média esperada durante a viagem? (km/h) \n"))
tempo = dist/vel
print("Numa viagem de %.1f kilometros, com a velocidade média de %.1fkm/h, a duração da viagem será de %.1f horas" %(dist, vel, tempo))

