from collections import deque


def ns(f):
    return next(f).strip()


with open("../testset/maze_shortest_path/test1.txt") as f:
    N, M = map(int, ns(f).split())
    A = [list(ns(f)) for _ in range(N)]

INF = int(1e7)
d = [[INF] * M for _ in range(N)]
di = [1, 0, -1, 0]
dj = [0, 1, 0, -1]

for i in range(N):
    for j in range(M):
        if A[i][j] == 'S':
            si = i
            sj = j
        if A[i][j] == 'G':
            gi = i
            gj = j


d[si][sj] = 0
q = deque([[si, sj]])
while len(q) > 0:
    _i, _j = q.popleft()
    if _i == gi and _j == gj:
        break
    for k in range(4):
        i = _i + di[k]
        j = _j + dj[k]
        if 0 <= i < N and 0 <= j < M and A[i][j] != '#' and d[i][j] == INF:
            d[i][j] = d[_i][_j] + 1
            q.append([i, j])
print(d[gi][gj])
