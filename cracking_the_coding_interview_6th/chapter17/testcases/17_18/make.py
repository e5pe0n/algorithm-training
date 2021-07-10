import random

fp = "02.txt"


long = [int(random.uniform(0, 20)) - 10 for _ in range(1000)]
short = list(range(-3, 3))
short_set = set(short)
left, right = 0, len(long)
for i in range(len(long)):
    for j in range(i + 1, len(long) + 1):
        _long = long[i:j]
        flag = True
        for v in short_set:
            flag &= v in _long
        if flag and j - i < right - left:
            right = j
            left = i

long_s = ' '.join(list(map(str, long)))
short_s = ' '.join(list(map(str, short)))
with open(fp, "w") as f:
    f.write(f"{len(long)} {len(short)}\n{long_s}\n{short_s}\n\nans: {left}, {right - 1}")
