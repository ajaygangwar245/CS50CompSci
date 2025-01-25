#square of a number

from cs50 import get_int

def square(n):
    return n * n

num = get_int("Number: ")
print(square(num))
