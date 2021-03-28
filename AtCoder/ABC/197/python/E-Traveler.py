from collections import defaultdict
INF = float('inf')
N = int(input())
M = defaultdict(list)
for _ in range(N):
    X, C = map(int, input().split())
    M[C].append(X)
for k in M:
    M[k].sort()
M[0].append(0)
V = [0] + sorted(list(M.keys())) + [0]
dp = [[INF, INF] for _ in range(len(V))]
dp[0][0] = dp[0][1] = 0
for i in range(len(V) - 1):
    prv_v = M[V[i]]
    prv_left = prv_v[0]
    prv_right = prv_v[-1]

    nxt_v = M[V[i + 1]]
    nxt_left = nxt_v[0]
    nxt_right = nxt_v[-1]

    # prv_left -> nxt_right -> nxt_left
    if prv_left <= nxt_right:
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + (nxt_right - prv_left) + (nxt_right - nxt_left))
    else:
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + (prv_left - nxt_left))
    # prv_right -> nxt_right -> nxt_left
    if prv_right <= nxt_right:
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (nxt_right - prv_right) + (nxt_right - nxt_left))
    else:
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + (prv_right - nxt_left))

    # prv_left -> nxt_left -> nxt_right
    if nxt_left <= prv_left:
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (prv_left - nxt_left) + (nxt_right - nxt_left))
    else:
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + (nxt_right - prv_left))
    # prv_right -> nxt_left -> nxt_right
    if nxt_left <= prv_right:
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (prv_right - nxt_left) + (nxt_right - nxt_left))
    else:
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + (nxt_right - prv_right))
print(dp[-1][0])
