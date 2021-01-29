from collections import deque
INF = float('inf')
di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]


def bfs(s, t):
    d = [[INF] * W for _ in range(H)]
    d[s][t] = 0
    q = deque([(s, t)])
    res = 0
    while len(q):
        i, j = q.popleft()
        for _di, _dj in zip(di, dj):
            _i = i + _di
            _j = j + _dj
            if 0 <= _i < H and 0 <= _j < W and S[_i][_j] == '.' and d[_i][_j] > d[i][j] + 1:
                d[_i][_j] = d[i][j] + 1
                res = max(res, d[_i][_j])
                q.append((_i, _j))
    return res


res = 0
for i in range(H):
    for j in range(W):
        if S[i][j] == '.':
            res = max(res, bfs(i, j))
print(res)
