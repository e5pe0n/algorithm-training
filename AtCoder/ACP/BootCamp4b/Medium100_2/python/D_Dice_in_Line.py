N, K = map(int, input().split())
P = list(map(int, input().split()))

sm = [0.0] * (N + 1)
for i in range(N):
    sm[i + 1] = sm[i] + (P[i] + 1) / 2
res = 0
for i in range(N - K + 1):
    res = max(res, sm[i + K] - sm[i])
print(f"{res:.7f}")
