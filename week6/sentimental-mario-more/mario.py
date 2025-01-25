from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height <= 8:
        break

for i in range(height):
    # left half of pyramid
    for x in range(height - i - 1):
        print(" ", end="")
    for y in range(i + 1):
        print("#", end="")
    # space between left & right half
    print("  ", end="")
    # right half of pyramid
    for z in range(i + 1):
        print("#", end="")
    print()
