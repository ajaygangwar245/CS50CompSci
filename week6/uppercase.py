# convert to uppercae

s = input("Before: ")
# print(f"After: {s.upper()}")

# alternate method
print("After:  ", end="")
for i in s:
    print(i.upper(), end="")
print()
