INF = float('inf')
cx, cy = map(int, input().split())
N = int(input())
XY = [list(map(int, input().split())) for _ in range(N)]
res = INF
for i in range(N):
    x0, y0 = XY[i]
    x1, y1 = XY[(i + 1) % N]
    p = abs(x0 * (y1 - cy) + x1 * (cy - y0) + cx * (y0 - y1))
    q = ((x0 - x1)**2 + (y0 - y1)**2)**0.5
    res = min(res, p / q)
print(f"{res:.7f}")
