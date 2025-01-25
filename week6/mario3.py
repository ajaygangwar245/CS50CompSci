#grid of bricks

from cs50 import get_int

while True:
    n = get_int("number: ")
    if n > 0:
        break

for i in range(n):
    print("#" * n)
