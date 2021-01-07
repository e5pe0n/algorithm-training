from collections import deque
INF = float('inf')
di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]

b = 0
for s in S:
    b += len(list(filter(lambda x: x == '#', s)))

d = [[INF] * W for _ in range(H)]
d[0][0] = 1


def bfs():
    global d
    q = deque([(0, 0)])
    while len(q) > 0:
        i, j = q.popleft()
        for _di, _dj in zip(di, dj):
            _i = i + _di
            _j = j + _dj
            if 0 <= _i < H and 0 <= _j < W and S[_i][_j] != '#' and d[_i][_j] > d[i][j] + 1:
                d[_i][_j] = d[i][j] + 1
                q.append((_i, _j))


bfs()
if d[-1][-1] == INF:
    res = -1
else:
    res = (H * W - d[-1][-1]) - b
print(res)
