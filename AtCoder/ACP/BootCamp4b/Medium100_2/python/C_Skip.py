from math import gcd


N, X = map(int, input().split())
x = sorted(list(map(int, input().split())))


dx = [x[i + 1] - x[i] for i in range(N - 1)]
g = dx[0] if len(dx) else 0
for i in range(N - 1):
    g = gcd(g, dx[i])
res = 0
for _x in x:
    res = max(res, gcd(g, abs(_x - X)))
print(res)
