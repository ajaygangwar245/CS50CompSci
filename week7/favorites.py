import csv

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    
    # next() ignores the current row(i.e., first row / header) and move to next
    next(reader)

    for row in reader:
        # prints 1st and 2nd index element in the row (i.e, 'language' and 'problem')
        print(f"{row[1]}, {row[2]}")
