# dictionary creation & usage
from cs50 import get_int

books = []

for i in range(3):
    book = dict()
    book["author"] = input("Author: ")
    book["book"] = input("Book: ")
    books.append(book)

# print all books and author
for book in books:
    print(book)

# print all keys
for book in books:
    print(book.keys())

# search for a book by author
for book in books:
    if book["author"] == "ajay":
        print(book["book"])
