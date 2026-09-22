import random

n = 1000001

for i in range(1, 6):
    
    numeros = list(range(1, n + 1))
    
    random.shuffle(numeros)
    
    nombre_archivo = f"input{i}_{n}.txt"
    with open(nombre_archivo, "w") as f:
        
        f.write(f"{n}\n")
        f.write(" ".join(map(str, numeros)) + "\n")
