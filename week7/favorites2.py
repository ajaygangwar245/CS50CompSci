import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    # initialize to count the favorite language
    # scratch = 0
    # c = 0
    # python = 0

    # alternate way
    scratch, c, python = 0, 0, 0

    for row in reader:
        if row["language"] == "Scratch":
            scratch += 1
        elif row["language"] == "C":
            c += 1
        elif row["language"] == "Python":
            python += 1

print(f"Scratch: {scratch}")
print(f"C: {c}")
print(f"Python: {python}")



