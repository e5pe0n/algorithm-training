from math import ceil
for i in range(1, 100000000):
    if int(ceil(i * (i + 1) / 2)) == 1225:
        print(i, i + 1)
