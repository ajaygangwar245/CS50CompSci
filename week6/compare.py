# compare two numbers
from cs50 import get_int

n1 = get_int("Number 1: ")
n2 = get_int("Number 2: ")

if n1 > n2:
    print(f"{n1} is greater than {n2}")
elif n1 < n2:
    print(f"{n1} is less than {n2}")
else:
    print(f"{n1} is equal to {n2}")
