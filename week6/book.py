# reading and using data from a csv file
import csv

books = []

with open("book.csv") as file:
    # DictReader reads file as a dictionary
    file_reader = csv.DictReader(file)
    for row in file_reader:
        books.append(row)

for book in books:
    print(book)
print()

# to read everything from book dictionary as plain text
with open("book.csv", "r") as file:
    text = file.read()
    print(text)



