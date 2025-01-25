# calculator for add, subtract, multiply, divide and power

from cs50 import get_int

val = True
while val == True:
    num1 = get_int("Number 1: ")
    num2 = get_int("Number 2: ")

    print("Choose the action you want to perform: \n1. Add 2. Subtract 3. Multiply 4. Divide 5. Power")
    ch = get_int("Choice: ")

    match ch:
        case 1:
            print(num1 + num2)
        case 2:
            print(num1 - num2)
        case 3:
            print(num1 * num2)
        case 4:
            print(num1 / num2)
        case 5:
            pow(num1, num2)
        case _:
            print("Wrong Input")

    print("Do you want to continue? (yes/no)")
    ans = input("Answer: ").lower()

    if ans in ['y', 'yes']:
        val = True
    else:
        val = False


