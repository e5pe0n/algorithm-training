INF = float('inf')
N = int(input())
res = INF
for _ in range(N):
    a, p, x = map(int, input().split())
    if x - a > 0:
        res = min(res, p)
if res == INF:
    res = -1
print(res)
