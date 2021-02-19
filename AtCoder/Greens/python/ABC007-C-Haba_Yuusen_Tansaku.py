from collections import deque
INF = float('inf')
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
R, C = map(int, input().split())
sy, sx = map(lambda x: int(x) - 1, input().split())
gy, gx = map(lambda x: int(x) - 1, input().split())
c = [list(input()) for _ in range(R)]

d = [[INF] * C for _ in range(R)]


def bfs():
    global d
    d[sy][sx] = 0
    q = deque([(sy, sx)])
    while q:
        y, x = q.popleft()
        for _dy, _dx in zip(dy, dx):
            _y = y + _dy
            _x = x + _dx
            if 0 <= _y < R and 0 <= _x < C and c[_y][_x] == '.' and d[_y][_x] > d[y][x] + 1:
                d[_y][_x] = d[y][x] + 1
                q.append((_y, _x))


bfs()
print(d[gy][gx])
