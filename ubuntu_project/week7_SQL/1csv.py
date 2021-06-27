import csv
with opne("TVShow.csv", "r") as file:
    reader = csv.reader(file)
    # next(file) is mean: skipping the first row because: heading
    next(file)
    # bor row[0]: vì thường là số TT
    for row in reader:
        print(row[1])
    # HOẶC
    reader = csv.DictReader(file)
    next(file)
    for row in reader:
        print(row("title"))
