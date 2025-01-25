people = [
    {
        "name": "ajay",
        "phone": "+91-101-202-8907"
    },
    {
        "name": "rahul",
        "phone": "+91-231-453-6789"
    },
    {
        "name": "raj",
        "phone": "+91-234-645-6789"
    }
]

name = input("Name: ")

for person in people:
    if name in person["name"]:
        number = person["phone"]
        print(f"found {number}")
        break
else:
    print("not found")
