INF = float('inf')
N = int(input())
max_z = -INF
min_z = INF
max_w = -INF
min_w = INF
for _ in range(N):
    x, y = map(int, input().split())
    z = x + y
    w = x - y
    max_z = max(max_z, z)
    min_z = min(min_z, z)
    max_w = max(max_w, w)
    min_w = min(min_w, w)
res = max(max_z - min_z, max_w - min_w)
print(res)
