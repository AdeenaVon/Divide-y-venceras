import subprocess
from pathlib import Path

carpeta = Path(__file__).parent
inputs = carpeta / "inputs"

programas = {
    "Ordena": "ord-selec.cpp",
    "Lomuto": "lomuto.cpp",
    "Med. Medianas": "med-de-med.cpp"
}

ejecutables = {}

# Compila los programas
for nombre, archivo in programas.items():
    ejecutable = carpeta / (Path(archivo).stem + ".exe")

    subprocess.run([
        "g++",
        "-std=c++17",
        "-O2",
        str(carpeta / archivo),
        "-o",
        str(ejecutable)
    ], check=True)

    ejecutables[nombre] = ejecutable

print("Programas compilados.\n")

# Obtener archivos de prueba
archivos = list(inputs.glob("input*.txt"))

# Ordenarlos por el tamaño n
def obtener_n(archivo):
    nombre = archivo.stem
    partes = nombre.split("_")
    return int(partes[-1])

archivos.sort(key=obtener_n)

# Ejecutar pruebas
for archivo in archivos:

    tiempos = {}
    medianas = []

    for nombre, ejecutable in ejecutables.items():

        with open(archivo, "r") as entrada:

            proceso = subprocess.run(
                [str(ejecutable)],
                stdin=entrada,
                capture_output=True,
                text=True
            )

        salida = proceso.stdout.strip().split()

        mediana = salida[0]
        tiempo = float(salida[1])

        medianas.append(mediana)
        tiempos[nombre] = tiempo

    if len(set(medianas)) == 1:
        estado = "OK"
    else:
        estado = "ERROR"

    print(
        archivo.name,
        "| Mediana:", medianas[0],
        "| Ordena:", round(tiempos["Ordena"], 3), "ms",
        "| Lomuto:", round(tiempos["Lomuto"], 3), "ms",
        "| Med. Medianas:", round(tiempos["Med. Medianas"], 3), "ms",
        "|", estado
    )