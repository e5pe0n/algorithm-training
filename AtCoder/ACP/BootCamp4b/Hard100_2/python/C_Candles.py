INF = float('inf')
N, K = map(int, input().split())
X = list(map(int, input().split()))

res = INF
for i in range(N - K + 1):
    if X[i] * X[i + K - 1] >= 0:
        res = min(res, max(abs(X[i]), abs(X[i + K - 1])))
    else:
        res = min(res, -X[i] + X[i + K - 1] + min(abs(X[i]), X[i + K - 1]))
print(res)
