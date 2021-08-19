class Rect:
    def __init__(self, lx, ly, rx, ry):
        self.lx = lx
        self.ly = ly
        self.rx = rx
        self.ry = ry


MAX_N = 100_000
MAX_X = MAX_Y = 1000
N = int(input())
rects = [Rect(*map(int, input().split())) for _ in range(N)]
cnt = [[0] * (MAX_X + 1) for _ in range(MAX_Y + 1)]
for r in rects:
    cnt[r.lx][r.ly] += 1
    cnt[r.lx][r.ry] -= 1
    cnt[r.rx][r.ly] -= 1
    cnt[r.rx][r.ry] += 1
for i in range(MAX_X + 1):
    for j in range(1, MAX_Y + 1):
        cnt[i][j] += cnt[i][j - 1]
for j in range(MAX_Y + 1):
    for i in range(1, MAX_X + 1):
        cnt[i][j] += cnt[i - 1][j]
A = [0] * (N + 1)
for i in range(MAX_X + 1):
    for j in range(MAX_Y + 1):
        if cnt[i][j] >= 1:
            A[cnt[i][j]] += 1
print('\n'.join(map(str, A[1:])))
