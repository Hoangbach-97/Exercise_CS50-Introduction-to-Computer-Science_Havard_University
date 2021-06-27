from string import digits
# from string import ascii_letters
# from string import digits, ascii_letters, punctuation
from itertools import product

# for passcode in product(digits+ascii_letters+punctuation, repeat=4):
for passcode in product(digits, repeat=4):
    print("".join(passcode))