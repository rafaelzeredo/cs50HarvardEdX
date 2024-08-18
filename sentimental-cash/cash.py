from cs50 import get_float
# import math

numberOfCoins = 0
centavos = 0
dolares = 0

globalInt = 0


while True:
    change = input("Change: ")
    howLongTheStringIs = len(change)
    if change.isdigit():
        change = int(change)
        if isinstance(change, (int, float)):
            if change > 0:
                break
            else:
                globalInt = 0
                # print("You must type a number bigger than zero")
        else:
            globalInt = 0
            # print("Invalid change. Please type an int or a float without the '$' dollar signs")
    elif "." in change:
        try:
            changeFloat = float(change)
            break
        except:
            globalInt = 0
            # print("Invalid change")
    else:
        globalInt = 0
        # print("Invalid change. Please type at least a number")


change = float(change)
centavos = change * 100
centavos = int(centavos % 100)
print(f"Cents {centavos}")
dolares = int(change)
print(f"Dolars {dolares}")
quarters = float(0.25)
quartersInDollars = 0
tens = float(0.10)
fives = float(0.5)
cents = float(0.1)
result1 = 0
result2 = 0
if dolares > 0:
    result1 = dolares / quarters
    quartersInDollars = int(result1)
    print(f"quarters in dolar {quartersInDollars}")
    dolares = 0
if centavos > 0:
    result2 = int(centavos / 25)
    print(f"quarters in cents {result2}")
    quarters = result2
print(f"Quarters: {quarters + quartersInDollars}")

centavos = centavos - (quarters*25)
print(f"Cents {centavos}")
quarters = quarters+quartersInDollars
# print(f"Centavos {centavos}")
# print(f"Dolares {dolares}")
# ate aqui tudo certo


tens = int(centavos / 10)
print(f"Tens: {tens}")
centavos = centavos - (tens*10)
# print(f"Centavos {centavos}")
# print(f"Centavos depois de tirar dezenas {centavos}")
# print(f"the result after removing tens is {change}")
# print(f"Change is now {change}")
fives = int(centavos / 5)
centavos = centavos - (fives*5)
print(f"Fives: {fives}")
# print(f"Centavos: {centavos}")
cents = centavos
print(f"Cents: {cents}")
# print(f"Centavos depois de tirar dezenas {centavos}")
# print(f"the result after removing tens is {change}")
numberOfCoins = quarters + tens + fives + cents
print(numberOfCoins)
