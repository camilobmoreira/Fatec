#

def mdc(a, b):
    while (a % b != 0):
        a, b = b, (a % b)
    return b

def mmc(a,b):
    return abs(a*b) / mdc(a,b)
