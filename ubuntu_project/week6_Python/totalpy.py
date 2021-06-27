from cs50 import get_int
# scores = [23, 23,57]
# a = (sum(scores)/len(scores))
# print(f"Avarage: {a} ")


scores = []
for i in range(4):
    scores.append(get_int("Input: "))
a = (sum(scores)/len(scores))
print(a)