names = ["ajay", "rahul", "saurabh"]

name = input("Name: ").lower()

if name in names:
    print("found")
else:
    print("not found")

# alternate method

# for i in names:
#     if name == i.lower():
#         print("found")
#         break
# else:
#     print("Not Found")
