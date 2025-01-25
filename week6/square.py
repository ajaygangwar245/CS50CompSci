# square of a number

from cs50 import get_int

def square(x):
    res = 0
    for i in range(0, x):
        res += x
    return res

num = get_int("Number: ")
print(square(num))
