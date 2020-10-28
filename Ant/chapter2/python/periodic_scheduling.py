def ns(f):
    return next(f).strip()


with open("../testset/periodic_scheduling/test1.txt", "r") as f:
    N = int(ns(f))
    S = list(map(int, ns(f).split()))
    T = list(map(int, ns(f).split()))

V = list(zip(T, S))
V.sort()
ans, t = 0, 0
for v in V:
    if t <= v[1]:
        ans += 1
        t = v[0]
print(ans)
