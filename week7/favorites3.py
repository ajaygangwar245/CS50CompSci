import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)

    # counts = dict()
    # alternate way
    counts = {}

    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

for favorite in counts:
    print(f"{favorite} : {counts[favorite]}")

# Alphabetically sorted by key
print()
print("Alphabetically Sorted")
for favorite in sorted(counts):
    print(f"{favorite} : {counts[favorite]}")

# sorted by value in ascending order (using 'key=counts.get' argument in 'sorted()')
print()
print("Sorted by value")
for favorite in sorted(counts, key=counts.get):
    print(f"{favorite} : {counts[favorite]}")

# sorted by value in descending order (using 'reverse=' argument in 'sorted()')
print()
print("Sorted by value")
for favorite in sorted(counts, key=counts.get, reverse=True):
    print(f"{favorite} : {counts[favorite]}")
