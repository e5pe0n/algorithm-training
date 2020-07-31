MAX_N = 1_000_000_000
A, B, X = list(map(int, input().split()))
M = len(str(min(X, MAX_N)))
res = 0
for i in range(1, M + 1):
    t = (X - B * i) // A
    if 1 <= t and i <= len(str(t)):
        res = max(res, min(t, MAX_N if i == len(str(MAX_N)) else 10 ** i - 1))
print(res)
