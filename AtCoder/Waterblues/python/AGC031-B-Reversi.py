from collections import Counter
MOD = 10**9 + 7
N = int(input())
C = [int(input()) for _ in range(N)]
sm = Counter()
V = [C[0]]
for c in C:
    if V[-1] != c:
        V.append(c)
N = len(V)
dp = [1] + [0] * N
for i in range(1, N + 1):
    dp[i] = (dp[i - 1] + sm[V[i - 1]]) % MOD
    sm[V[i - 1]] = dp[i]
print(dp[-1])
