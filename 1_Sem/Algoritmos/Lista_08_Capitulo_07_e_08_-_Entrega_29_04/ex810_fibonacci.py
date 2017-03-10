#

def fibonacci(x):
    f = [1]
    a = 0
    for indice in range(x - 1):
        f, a = f + a, f
        print(f)
        #f.append(f[indice] + a)
        #a = f[indice]
    return f

print(fibonacci(7))