from bisect import bisect_left, bisect


def ns(f):
    return next(f).strip()


with open("../testset/4_values_whose_sum_is_0/test1.txt", 'r') as f:
    n = int(ns(f))
    A = list(map(int, ns(f).split()))
    B = list(map(int, ns(f).split()))
    C = list(map(int, ns(f).split()))
    D = list(map(int, ns(f).split()))


CD = []
for c in C:
    for d in D:
        CD.append(c + d)
CD.sort()
ans = 0
for a in A:
    for b in B:
        cd = -(a + b)
        ans += bisect(CD, cd) - bisect_left(CD, cd)
print(ans)
