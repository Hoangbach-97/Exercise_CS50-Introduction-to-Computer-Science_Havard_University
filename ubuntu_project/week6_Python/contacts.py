from cs50 import get_string

contacts = {
    "Tuan Anh": "+84 353 4343",
    "Hoang Bach": "+84 3433 433"
}

name = get_string("Input name: ")
if name in contacts:
    print(f"Phone number of {name} is {contacts[name]}")
else:
    print("Not found")