N, X = map(int, input().split())
A = list(map(int, input().split()))

res = 0
for i in range(N - 1):
    d = A[i] + A[i + 1] - X
    if d > 0:
        res += d
        A[i + 1] = max(0, A[i + 1] - d)
print(res)
