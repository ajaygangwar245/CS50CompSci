import csv

from collections import Counter

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = Counter()

    for row in reader:
        # favorite = row["language"]

        # for counting problems
        favorite = row["problem"]
        
        # Counter() automatically assign keys and values according to condition
        counts[favorite] += 1

# for favorite in sorted(counts, key=counts.get, reverse=True):
#     print(f"{favorite} : {counts[favorite]}")

# Alternate way
# .most_common() returns key-value pair sorted by most common value
for favorite, count in counts.most_common():
    print(f"{favorite}: {count}")


