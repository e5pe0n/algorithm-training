from collections import deque

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]

H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]


def bfs():
    q = deque()
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#':
                q.append((i, j, 0))
    res = 0
    while len(q):
        i, j, c = q.popleft()
        for _di, _dj in zip(di, dj):
            _i = i + _di
            _j = j + _dj
            if 0 <= _i < H and 0 <= _j < W and A[_i][_j] == '.':
                q.append((_i, _j, c + 1))
                res = max(res, c + 1)
                A[_i][_j] = '#'
    return res


print(bfs())
