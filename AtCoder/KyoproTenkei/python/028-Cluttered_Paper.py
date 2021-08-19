class Rect:
    def __init__(self, lx, ly, rx, ry):
        self.lx = lx
        self.ly = ly
        self.rx = rx
        self.ry = ry


MAX_X = MAX_Y = 1000
N = int(input())
rects = [Rect(*map(int, input().split())) for _ in range(N)]
A = [0] * (N + 1)
lefts = [[0] * (MAX_X + 1) for _ in range(MAX_Y + 1)]
rights = [[0] * (MAX_X + 1) for _ in range(MAX_Y + 1)]
for y in range(MAX_Y + 1):
    for rect in rects:
        if rect.ly <= y < rect.ry:
            lefts[y][rect.lx] += 1
            rights[y][rect.rx] += 1
for y in range(MAX_Y + 1):
    k = 0
    for x in range(MAX_X + 1):
        k -= rights[y][x]
        k += lefts[y][x]
        A[k] += 1
print('\n'.join(map(str, A[1:])))
