H, W = map(int, input().split())

board = [[False] * W for _ in range(H)]
par = list(range(H * W))
rnk = [0] * (H * W)

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]


def find(u):
    global par
    if par[u] == u:
        return u
    par[u] = find(par[u])
    return par[u]


def unite(u, v):
    u = find(u)
    v = find(v)
    if u == v:
        return
    if rnk[u] < rnk[v]:
        par[u] = v
    else:
        par[v] = u
        if rnk[u] == rnk[v]:
            rnk[u] += 1


def same(u, v):
    return find(u) == find(v)


def vertex(i, j):
    return i * W + j


Q = int(input())
for _ in range(Q):
    t, *q = map(int, input().split())
    if t == 1:
        r, c = map(lambda x: x - 1, q)
        board[r][c] = True
        for _di, _dj in zip(di, dj):
            _r = r + _di
            _c = c + _dj
            if 0 <= _r < H and 0 <= _c < W and board[_r][_c]:
                unite(vertex(_r, _c), vertex(r, c))
    else:
        ra, ca, rb, cb = map(lambda x: x - 1, q)
        if board[ra][ca] and board[rb][cb] and same(vertex(ra, ca), vertex(rb, cb)):
            print("Yes")
        else:
            print("No")
