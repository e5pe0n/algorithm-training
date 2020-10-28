def ns(f):
    return next(f).strip()


with open("../testset/knapsack_problem_without_limitations/test1.txt", 'r') as f:
    N, W = map(int, ns(f).split())
    P = [list(map(int, ns(f).split())) for _ in range(N)]   # (w, v)


dp = [0] * (W + 1)
for i in range(N):
    for j in range(P[i][0], W + 1):
        dp[j] = max(dp[j], dp[j - P[i][0]] + P[i][1])
print(W)
