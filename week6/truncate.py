# to show no truncation & no integer overflow in python like C
from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

z = x / y
# no truncation
print(z)

# but floating point imprecision still exists
print(f"{z:.50f}")
