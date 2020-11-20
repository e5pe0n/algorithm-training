from collections import deque


H, W = map(int, input().split())
Ch, Cw = map(lambda x: int(x) - 1, input().split())
Dh, Dw = map(lambda x: int(x) - 1, input().split())
S = [input() for _ in range(H)]

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
d = [[-1] * W for _ in range(H)]


def bfs(V, cost):
    global d
    _V = []
    for v in V:
        i, j = v
        if d[i][j] >= 0:
            continue
        d[i][j] = cost
        q = deque([[i, j]])
        _V.append([i, j])
        while len(q) > 0:
            i, j = q.popleft()
            for _di, _dj in zip(di, dj):
                _i = i + _di
                _j = j + _dj
                if 0 <= _i < H and 0 <= _j < W and S[_i][_j] == '.' and d[_i][_j] < 0:
                    d[_i][_j] = cost
                    q.append([_i, _j])
                    _V.append([_i, _j])
    return _V


V = [[Ch, Cw]]
cost = 0
while len(V) > 0:
    _V = bfs(V, cost)
    cost += 1
    V = []
    for _v in _V:
        for _di in range(-2, 3):
            for _dj in range(-2, 3):
                i = _v[0] + _di
                j = _v[1] + _dj
                if 0 <= i < H and 0 <= j < W and S[i][j] == '.' and d[i][j] < 0:
                    V.append([i, j])
print(d[Dh][Dw])
