#

def validaString(texto, min, max):
    texto = texto.strip()
    if len(texto) in range (min, max + 1):
        return True
    else:
        return False
