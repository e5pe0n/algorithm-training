def ns(f):
    return next(f).strip()


with open("../testset/sarumans_army/test1.txt", "r") as f:
    N, R = map(int, ns(f).split())
    X = list(map(int, ns(f).split()))


X.sort()
i, res = 0, 0
while i < N:
    s = X[i]
    i += 1
    while i < N and X[i] <= s + R:
        i += 1
    p = X[i - 1]
    while i < N and X[i] <= p + R:
        i += 1
    res += 1
print(res)
