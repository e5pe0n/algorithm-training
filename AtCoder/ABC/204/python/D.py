N = int(input())
T = list(map(int, input().split()))

S = sum(T)
S2 = (S + 2 - 1) // 2

dp = [[False] * (S + 1) for _ in range(N + 1)]
for i in range(N):
    dp[i][0] = True

for i in range(1, N + 1):
    for j in range(S):
        if dp[i - 1][j]:
            dp[i][j] = True
            if j + T[i - 1] <= S:
                dp[i][j + T[i - 1]] = True
for j in range(S2, S + 1):
    if dp[N][j]:
        print(j)
        exit()
