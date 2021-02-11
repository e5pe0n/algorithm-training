N, K, M, R = map(int, input().split())
S = sorted([0] + [int(input()) for _ in range(N - 1)])[N-K:N]
sm = sum(S)
if sm >= R * K:
    res = 0
else:
    res = R * K - (sm - S[0])
    if res > M:
        res = -1
print(res)
