import cs50

x = cs50.get_int("x: ")
y = cs50.get_int("y: ")

if x > y:
    print("x great than y")
elif x < y:
    print("x less than y")
else:
    print("x equal y")