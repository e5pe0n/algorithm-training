def ns(f):
    return next(f).strip()


with open("../testset/millionaire/test2.txt", 'r') as f:
    M, P, X = map(float, ns(f).split())
    M = int(M)
    X = int(X)

n = 1 << M
dp = [[0.0] * (n + 1) for _ in range(2)]
prv = dp[0]
nxt = dp[1]
prv[n] = 1.0
for r in range(M):
    for i in range(n + 1):
        jub = min(i, n - i)
        t = 0.0
        for j in range(jub + 1):
            t = max(t, P * prv[i + j] + (1 - P) * prv[i - j])
        nxt[i] = t
    prv, nxt = nxt, prv
i = X * n // 1000000
print(f"{prv[i]:.6f}")
