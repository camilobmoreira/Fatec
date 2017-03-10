texto= (input("Digite um texto: "))
texto = str(texto)
ind=0
result=''
while ind < len(texto):
    result = texto [ind] + result
    ind +=1
if texto == result:
    print ('O texto é palindromo.')
else:
    print('O texto não é palindromo.')