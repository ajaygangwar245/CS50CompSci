from cs50 import get_int

while True:
    height = get_int("Height: ")
    # checks if user input is greater than 0 and less sthan 8
    if height > 0 and height < 9:
        break

for i in range(height):
    # prints spaces
    for j in range(height - i - 1):
        print(" ", end="")
    # prints '#' after spaces
    for k in range(i + 1):
        print("#", end="")
    print()
