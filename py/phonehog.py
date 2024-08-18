import csv

sexos = {
    "masculino": 0,
    "feminino": 0,
}

with open("phonebook.csv", "r") as file:
    reader = csv.reader(file)

    for row in reader:
        sexo = row[2]
        sexos[sexo] += 1

for sexo in sexos:
    count = sexos[sexo]
    print(f"{house}: {count}")