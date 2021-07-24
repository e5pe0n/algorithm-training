from sys import setrecursionlimit
setrecursionlimit(10**9)

di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
used = set()
res = 0


def get_bit(n, i):
    return (n & (1 << i)) != 0


def set_bit(n, i):
    return n | (1 << i)


def idx(i, j):
    return i * N + j


N = int(input())
K = int(input())
S = [list(input()) for _ in range(N)]


def dfs(r, board):
    global used, res
    if board in used:
        return
    used.add(board)
    if r == K:
        res += 1
        return
    nxts = []
    for i in range(N):
        for j in range(N):
            if S[i][j] == '#':
                continue
            f = False
            for _di, _dj in zip(di, dj):
                _i = i + _di
                _j = j + _dj
                if 0 <= _i < N and 0 <= _j < N and get_bit(board, idx(_i, _j)):
                    f = True
            if f:
                nxts.append((i, j))
    for i, j in nxts:
        dfs(r + 1, set_bit(board, idx(i, j)))


for i in range(N):
    for j in range(N):
        if S[i][j] != '#':
            dfs(1, set_bit(0, idx(i, j)))

print(res)
