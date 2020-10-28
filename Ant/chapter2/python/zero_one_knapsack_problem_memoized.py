def ns(f):
    return next(f).strip()


with open("../testset/zero_one_knapsack_problem/test1.txt", "r") as f:
    N, W = map(int, ns(f).split())
    P = [list(map(int, ns(f).split())) for _ in range(N)]   # (w, v)

dp = [[-1] * (W + 1) for _ in range(N + 1)]


def rec(i, j):
    global dp
    if dp[i][j] >= 0:
        return dp[i][j]
    res = 0
    if i == N:
        res = 0
    elif j < P[i][0]:
        res = rec(i + 1, j)
    else:
        res = max(rec(i + 1, j), rec(i + 1, j - P[i][0]) + P[i][1])
    return res


res = rec(0, W)
print(res)
