def ns(f):
    return next(f).strip()


V = [1, 5, 10, 50, 100, 500]
with open("../testset/coin_choice/test1.txt", "r") as f:
    C = list(map(int, ns(f).split()))
    A = int(ns(f))


ans = 0
for i in range(5, -1, -1):
    t = min(A // V[i], C[i])
    A -= V[i] * t
    ans += t
print(ans)
