# using exceptions in python to built get_int() function

def get_int(prompt):
    while True:
        try:
            return int(input(prompt))
        except ValueError:
            # print("Not an Integer")
            pass

num = get_int("Number: ")
print(num)
