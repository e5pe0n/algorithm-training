def ns(f):
    return next(f).strip()


with open("../testset/minimum_scalar_product/test2.txt", 'r') as f:
    n = int(ns(f))
    v1 = list(map(int, ns(f).split()))
    v2 = list(map(int, ns(f).split()))

v1.sort()
v2.sort()
ans = 0
for i in range(n):
    ans += v1[i] * v2[n - 1 - i]
print(ans)
