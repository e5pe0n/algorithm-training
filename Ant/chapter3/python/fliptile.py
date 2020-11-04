from copy import deepcopy


def ns(f):
    return next(f).strip()


with open("../testset/fliptile/test1.txt", 'r') as f:
    M, N = map(int, ns(f).split())
    tile = [list(map(int, ns(f).split())) for _ in range(M)]


work = []
opt = []

di = [-1, 0, 1, 0, 0]
dj = [0, -1, 0, 1, 0]


def get(_i, _j):
    c = tile[_i][_j]
    for _di, _dj in zip(di, dj):
        i = _i + _di
        j = _j + _dj
        if 0 <= i < M and 0 <= j < N:
            c += work[i][j]
    return c % 2


def calc():
    global work
    for i in range(1, M):
        for j in range(N):
            if get(i - 1, j):
                work[i][j] = 1
    for j in range(N):
        if get(M - 1, j):
            return -1
    return sum(map(sum, work))


ans = -1
for i in range(1 << N):
    work = [[0] * N for _ in range(M)]
    work[0] = list(map(lambda j: i >> j & 1, range(N)))
    res = calc()
    if res >= 0 and (ans < 0 or ans > res):
        ans = res
        opt = deepcopy(work)

if ans < 0:
    print("IMPOSSIBLE")
else:
    for _opt in opt:
        print(" ".join(list(map(str, _opt))))
