INF = float('inf')
N = int(input())
A = list(map(int, input().split()))
sm = [0] * (N + 1)
for i in range(N):
    sm[i + 1] = sm[i] + A[i]
res = INF
for i in range(1, N):
    res = min(res, abs(sm[N] - sm[i] - sm[i]))
print(res)
