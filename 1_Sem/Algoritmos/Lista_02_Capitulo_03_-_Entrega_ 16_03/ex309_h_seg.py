#Recebe um valor em dias, horas, minutos e segundos e retorna o total em segundos
total_seg = 0
dias = int(input("Entre com o valor em dias \n"))
total_seg = total_seg + (dias * 24 * 60 * 60) #Transforma de dias para segundos e soma
horas = int(input("Entre com o valor em horas \n"))
total_seg = total_seg + (horas * 60 * 60) #Transforma de horas para segundos e soma
min = int(input("Entre com o valor em minutos \n"))
total_seg = total_seg + (min * 60) #Transforma de minutos para segundos e soma 
seg = int(input("Entre com o valor em segundos \n"))
total_seg = total_seg + seg #Soma com o valor anterior da variavel

print("O valor total em segundos é %i" %total_seg)
