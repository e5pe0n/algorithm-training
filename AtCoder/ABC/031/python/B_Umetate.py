from collections import deque
import sys


N = 10


def f(i, j, C, D):
    return 0 <= i < N and 0 <= j < N and C[i][j] == 'o' and not D[i][j]


def bfs(i, j, D):
    dq = deque(((i, j),))
    cnt = 0
    while len(dq) > 0:
        _i, _j = dq.popleft()
        for _x, _y in ((_i - 1, _j), (_i + 1, _j), (_i, _j - 1), (_i, _j + 1)):
            if f(_x, _y, C, D):
                dq.append((_x, _y))
                D[_x][_y] = True
                cnt += 1
    return cnt


C = [[c for c in input()] for _ in range(N)]
cnt = sum(len(tuple(filter(lambda x: x == 'o', c))) for c in C)

for i in range(N):
    for j in range(N):
        if C[i][j] == 'x':
            D = [[False] * N for _ in range(N)]
            _cnt = bfs(i, j, D)
            if _cnt == cnt:
                print('YES')
                sys.exit()
print('NO')
