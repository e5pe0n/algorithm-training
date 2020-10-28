MAX_N = 100
MAX_V = 100
INF = float('inf')
V = MAX_N * MAX_V


def ns(f):
    return next(f).strip()


with open("../testset/zero_one_knapsack_problem/test1.txt", 'r') as f:
    N, W = map(int, ns(f).split())
    P = [list(map(int, ns(f).split())) for _ in range(N)]   # (w, v)


dp = [[INF] * (V + 1) for _ in range(N + 1)]
dp[0][0] = 0
for i in range(N):
    for j in range(V + 1):
        if j < P[i][1]:
            dp[i + 1][j] = dp[i][j]
        else:
            dp[i + 1][j] = min(dp[i][j], dp[i][j - P[i][1]] + P[i][0])
res = 0
for j in range(V + 1):
    if dp[N][j] <= W:
        res = j
print(res)
