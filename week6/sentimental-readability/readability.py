from cs50 import get_string

text = get_string("Text: ")

# total letters in text
letters = 0
for i in text:
    if i.isalpha():
        letters += 1

# total words in text
wordList = text.split()
words = len(wordList)

# total sentences in text
sentences = text.count(".") + text.count("!") + text.count("?")

L = (letters / words) * 100
S = (sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
