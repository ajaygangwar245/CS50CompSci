text = "   In tHe Great green RooM    "

print(f"Before: {text}")

# remove extra spaces from start and end of text
text = text.strip()
print(f"After: {text}")

# convert to lower case
text = text.lower()
print(f"Lowercase: {text}")

# convert to upper case
text = text.upper()
print(f"Uppercase: {text}")

# capitalize first letter
text = text.capitalize()
print(f"Capitalized: {text}")
print()

# print each letter in the text
for c in text:
    print(c)
print()

# print each word in the text
words = text.split()
print(words)
print()

for word in words:
    print(word)
print()

# print words from a specific index in list
words = text.split()
for word in words[2:]:
    print(word)
print()

for word in words[2:4]:
    print(word)
print()
