INF = float('inf')
H, N = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]
dp = [0] + [INF] * H
for i in range(H):
    for a, b in AB:
        nxt = min(H, i + a)
        dp[nxt] = min(dp[nxt], dp[i] + b)
print(dp[H])
