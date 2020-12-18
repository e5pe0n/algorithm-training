MAX_N = 10**9
A, B, X = map(int, input().split())
if A * MAX_N + B * 10 <= X:
    print(MAX_N)
    exit()
res = 0
for i in range(1, 10):
    n = int("9" * i)
    x = X - B * i
    if x <= 0:
        break
    res = max(res, min(n, x // A))
print(res)
