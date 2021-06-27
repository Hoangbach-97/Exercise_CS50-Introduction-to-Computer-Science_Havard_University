from cs50 import get_int

def main():
    i = get_positive()
    print(i)

def get_positive():

    while True:
        n = get_int("Input number positive: ")
        if n > 0:
            break
    return n
main()