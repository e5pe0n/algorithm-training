INF = float('inf')


def ns(f):
    return next(f).strip()


with open("../testset/bride_the_prisoners/test3.txt", 'r') as f:
    P, Q = map(int, ns(f).split())
    A = [0] + list(map(int, ns(f).split())) + [P + 1]


dp = [[0] * (Q + 2) for _ in range(Q + 1)]
for w in range(2, Q + 2):
    for i in range(0, Q + 2 - w):
        j = i + w
        t = INF
        for k in range(i + 1, j):
            t = min(t, dp[i][k] + dp[k][j])
        dp[i][j] = A[j] - A[i] - 2 + t
print(dp[0][Q + 1])
