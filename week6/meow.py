# print meow upto number times user wants
from cs50 import get_int

def meow(n):
    for i in range(n):
        print("meow")

num = get_int("Number: ")
meow(num)
