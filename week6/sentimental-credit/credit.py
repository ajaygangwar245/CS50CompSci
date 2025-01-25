from cs50 import get_int
import re

# checks for card number is valid or not via Luhn's Algorithm


def check(cardNum):
    sumOfProduct = 0
    sumOfLeftDigits = 0

    while cardNum != 0:
        # last & second last digits of the card
        lastDigit = cardNum % 10
        secondLast = (cardNum // 10) % 10

        # multiply second last digit with 2
        product = secondLast * 2

        # check if product is greater than 10 then make it less than 10
        if product >= 10:
            product = (product // 10) + (product % 10)

        # sum of products of second last and it's consecutive digits
        sumOfProduct += product

        # sum of remaining digits
        sumOfLeftDigits += lastDigit
        cardNum //= 100

    # calculates checksum and returns it
    checkSum = sumOfProduct + sumOfLeftDigits
    return checkSum


# get user input
number = get_int("Number: ")

# stores checksum returned from function
checksum = check(number)

# convert card number to string to use RegEx
card = str(number)

# if last digit of checksum is equals to 0
if checksum % 10 == 0:
    # if card number starts with '34' or '37' and have total 15 digits
    if re.search("^3[4, 7].{13}", card):
        print("AMEX")

    # if card number starts with '51' or '52' or '53' or '54' or '55' and have total 16 digits
    elif re.search("^5[1, 2, 3, 4, 5].{14}", card):
        print("MASTERCARD")

    # if card number starts with '4' and have total 13 or 16 digits
    elif re.search("^4.{12}", card) or re.search("^4.{15}", card):
        print("VISA")

    # if card don't match above requirements
    else:
        print("INVALID")
else:
    print("INVALID")
