people = {
    "ajay": "+91-123-456-7890",
    "rahul": "+91-890-567-1234",
    "spidy": "+91-321-654-0987"
}

name = input("Name: ").lower()

if name in people:
    number = people[name]
    print(f"found {number}")
else:
    print("not found"6lecture
    )
