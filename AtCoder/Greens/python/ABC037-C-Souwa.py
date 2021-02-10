N, K = map(int, input().split())
A = list(map(int, input().split()))
sm = [0] * (N + 1)
for i in range(N):
    sm[i + 1] = sm[i] + A[i]
res = 0
for i in range(N - K + 1):
    res += sm[i + K] - sm[i]
print(res)
