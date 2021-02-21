INF = float('inf')
N = int(input())
C = input()

cmd = ['A', 'B', 'X', 'Y']
res = INF
for i in range(4):
    for j in range(4):
        for _i in range(4):
            for _j in range(4):
                L = cmd[i] + cmd[j]
                R = cmd[_i] + cmd[_j]
                dp = [0] + [INF] * N
                for k in range(1, N + 1):
                    if k - 1 >= 0:
                        dp[k] = min(dp[k], dp[k - 1] + 1)
                    if k - 2 >= 0:
                        _C = C[k - 2:k]
                        if _C == L or _C == R:
                            dp[k] = min(dp[k], dp[k - 2] + 1)
                res = min(res, dp[N])
print(res)
