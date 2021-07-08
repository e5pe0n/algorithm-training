import random

n = 1000
k = 100
fp = "03.txt"

lst = [int(random.uniform(-10, 1000)) for _ in range(n)]

ans = sorted(lst)[:k]

with open(fp, "w") as f:
    f.write(f"{n} {k}\n{' '.join(list(map(str, lst)))}\n\nans: {' '.join(list(map(str, ans)))}")
