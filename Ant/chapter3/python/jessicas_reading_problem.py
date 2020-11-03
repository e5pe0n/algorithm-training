from collections import Counter


def ns(f):
    return next(f).strip()


with open("../testset/jessicas_reading_problem/test2.txt", 'r') as f:
    P = int(ns(f))
    a = list(map(int, ns(f).split()))

n = len(set(a))
i, j, _n = 0, 0, 0
cnt = Counter()
res = P
while True:
    while j < P and _n < n:
        if cnt[a[j]] == 0:
            _n += 1
        cnt[a[j]] += 1
        j += 1
    if _n < n:
        break
    res = min(res, j - i)
    cnt[a[i]] -= 1
    if cnt[a[i]] == 0:
        _n -= 1
    i += 1
print(res)
