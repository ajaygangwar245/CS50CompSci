# take scores from user input and calculate average
from cs50 import get_int

scores = []
n = get_int("Number of scores to add: ")

for i in range(n):
    score = get_int("score: ")
    # appends the score to end of list
    scores.append(score)
    # scores = scores + [score]

average = sum(scores) / len(scores)
print(f"Average: {average}")
