import sys

if len(sys.argv) !=2:
    print("Missing arguments!")
    sys.exit(1)
else:
    print(sys.argv[1])
    sys.exit(0)
