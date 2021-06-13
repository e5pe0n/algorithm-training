def ns(f):
    return next(f).strip()


fp = "03.txt"

with open(fp) as f:
    n = int(ns(f))
    v = list(map(int, ns(f).split()))


res = 0
for i in range(n):
    for j in range(i, n):
        s = 0
        for k in range(i, j + 1):
            s += v[k]
        if res < s:
            res = s
            left = i
            right = j
print(res)
print(left, right)
