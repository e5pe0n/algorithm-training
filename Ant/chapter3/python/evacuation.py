from heapq import heapify, heappop, heappush


def ns(f):
    return next(f).strip()


with open("../testset/evacuation/test3.txt", 'r') as f:
    X, Y = map(int, ns(f).split())
    field = [list(ns(f)) for _ in range(X)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

N = X * Y
G = [[] for _ in range((N + 1) * (X + Y))]
dist = [[[[-1] * Y for _ in range(X)] for _ in range(Y)] for _ in range(X)]


def bfs(x, y, d):
    d[x][y] = 0
    qx = [x]
    qy = [y]
    heapify(qx)
    heapify(qy)
    while len(qx) > 0:
        x = heappop(qx)
        y = heappop(qy)
        for _dx, _dy in zip(dx, dy):
            _x = x + _dx
            _y = y + _dy
            if 0 <= _x < X and 0 <= _y < Y and field[_x][_y] == '.' and d[_x][_y] < 0:
                d[_x][_y] = d[x][y] + 1
                heappush(qx, _x)
                heappush(qy, _y)


dX = []
dY = []
pX = []
pY = []
for x in range(X):
    for y in range(Y):
        if field[x][y] == 'D':
            dX.append(x)
            dY.append(y)
            bfs(x, y, dist[x][y])
        elif field[x][y] == '.':
            pX.append(x)
            pY.append(y)


def add_edge(u, v):
    G[u].append(v)
    G[v].append(u)


D = len(dX)
P = len(pX)
for i in range(D):
    for j in range(P):
        if dist[dX[i]][dY[i]][pX[j]][pY[j]] >= 0:
            for k in range(dist[dX[i]][dY[i]][pX[j]][pY[j]], N + 1):
                add_edge((k - 1) * D + i, N * D + j)
if P == 0:
    print(0)
    exit()

match = [-1] * ((N + 1) * (X + Y))


def dfs(u, used):
    global match
    used[u] = True
    for v in G[u]:
        _u = match[v]
        if _u < 0 or (not used[_u] and dfs(_u, used)):
            match[u] = v
            match[v] = u
            return True
    return False


cnt = 0
for u in range(N * D):
    used = [False] * ((N + 1) * (X + Y))
    if dfs(u, used):
        cnt += 1
        if cnt == P:
            print(u // D + 1)
            exit()
print('impossible')
