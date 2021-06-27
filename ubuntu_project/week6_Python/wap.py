from cs50 import get_int

x = get_int("Input: ")
y = get_int("Input: ")
print("Before: ", end="")
print(f"x: {x}, y: {y}")
x ,y = y, x
print("After: ", end = "")
print(f"x: {x}, y: {y}")