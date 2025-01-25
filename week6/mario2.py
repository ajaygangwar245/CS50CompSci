from cs50 import get_int

while True:
    len = get_int("Length: ")
    if len > 0:
        break

for i in range(len):
    print("?", end="")
print()

# alternate method
print("?" * len)
