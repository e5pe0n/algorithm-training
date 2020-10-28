def ns(f):
    return next(f).strip()


with open("../testset/zero_one_knapsack_problem/test1.txt", 'r') as f:
    N, W = map(int, ns(f).split())
    P = [list(map(int, ns(f).split())) for _ in range(N)]   # (w, v)


dp = [0] * (W + 1)
for i in range(N):
    for j in range(W, P[i][0] - 1, -1):
        dp[j] = max(dp[j], dp[j - P[i][0]] + P[i][1])
print(dp[W])
