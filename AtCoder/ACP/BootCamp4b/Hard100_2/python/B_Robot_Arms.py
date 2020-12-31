INF = float('inf')
N = int(input())
V = []
for _ in range(N):
    X, L = map(int, input().split())
    V.append((X + L, X - L))
V.sort()
res = 0
t = -INF
for v in V:
    if t <= v[1]:
        t = v[0]
        res += 1
print(res)
