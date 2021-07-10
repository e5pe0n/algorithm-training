from collections import defaultdict


def ns(f):
    return next(f).strip()


fp = "02.txt"

with open(fp) as f:
    s = ns(f)
    n = int(ns(f))
    T = [ns(f) for _ in range(n)]

d = defaultdict(list)
for t in T:
    for i in range(len(s) - 1):
        if t == s[i:i+len(t)]:
            d[t].append(i)

with open(fp, "a") as f:
    s = '\n'.join(list(map(lambda x: f"{x} : {', '.join(list(map(str, d[x])))}", d)))
    f.write(f"\nans:\n{s}")
