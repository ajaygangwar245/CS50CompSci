from cs50 import get_float

while True:
    change = get_float("Change owed: ")
    if change >= 0:
        break

quarters = int(change / 0.25)
change = change % 0.25

dimes = int(change / 0.10)
change = change % 0.10

cents = int(change / 0.04)
change = change % 0.04

pennies = int(change / 0.01)

print(quarters + dimes + cents + pennies)
