H, N = map(int, input().split())
C = [list(map(int, input().split())) for _ in range(N)]

dp = [0] + [float('inf')] * H
for i in range(H):
    for j in range(N):
        A, B = C[j]
        nxt = min(H, i + A)
        dp[nxt] = min(dp[nxt], dp[i] + B)
print(dp[H])
