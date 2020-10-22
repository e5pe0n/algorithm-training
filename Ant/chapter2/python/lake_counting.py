def ns(f):
    return next(f).strip()


with open("../testset/lake_counting/test1.txt") as f:
    N, M = map(int, ns(f).split())
    A = [list(ns(f)) for _ in range(N)]


def dfs(_i, _j):
    A[_i][_j] = '.'
    for di in range(-1, 2):
        for dj in range(-1, 2):
            i = _i + di
            j = _j + dj
            if 0 <= i < N and 0 <= j < M and A[i][j] == 'W':
                dfs(i, j)


res = 0
for i in range(N):
    for j in range(M):
        if A[i][j] == 'W':
            dfs(i, j)
            res += 1
print(res)
