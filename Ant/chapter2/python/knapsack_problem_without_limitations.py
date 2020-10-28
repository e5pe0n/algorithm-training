def ns(f):
    return next(f).strip()


with open("../testset/knapsack_problem_without_limitations/test1.txt", 'r') as f:
    N, W = map(int, ns(f).split())
    P = [list(map(int, ns(f).split())) for _ in range(N)]   # (w, v)


dp = [[0] * (W + 1) for _ in range(N + 1)]
for i in range(N):
    for j in range(W + 1):
        if j < P[i][0]:
            dp[i + 1][j] = dp[i][j]
        else:
            dp[i + 1][j] = max(dp[i][j], dp[i + 1][j - P[i][0]] + P[i][1])
print(dp[N][W])
