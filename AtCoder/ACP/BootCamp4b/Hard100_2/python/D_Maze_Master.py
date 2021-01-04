from collections import deque
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]


def bfs(sx, sy):
    res = 0
    q = deque([(sx, sy, 0)])
    used = [[False] * W for _ in range(H)]
    used[sx][sy] = True
    while len(q) > 0:
        x, y, d = q.popleft()
        for _dx, _dy in zip(dx, dy):
            _x = x + _dx
            _y = y + _dy
            if 0 <= _x < H and 0 <= _y < W and S[_x][_y] != '#' and not used[_x][_y]:
                used[_x][_y] = True
                q.append((_x, _y, d + 1))
                res = max(res, d + 1)
    return res


res = 0
for i in range(H):
    for j in range(W):
        if S[i][j] != '#':
            res = max(res, bfs(i, j))
print(res)
