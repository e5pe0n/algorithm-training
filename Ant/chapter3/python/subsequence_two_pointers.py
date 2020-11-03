def ns(f):
    return next(f).strip()


with open("../testset/subsequence/test2.txt", 'r') as f:
    n, S = map(int, ns(f).split())
    a = list(map(int, ns(f).split()))


i, j, s = 0, 0, 0
res = n + 1
while True:
    while j < n and s < S:
        s += a[j]
        j += 1
    if s < S:
        break
    res = min(res, j - i)
    s -= a[i]
    i += 1
if res > n:
    res = 0
print(res)
