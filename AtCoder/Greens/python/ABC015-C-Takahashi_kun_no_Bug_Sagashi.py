N, K = map(int, input().split())
T = [list(map(int, input().split())) for _ in range(N)]


def dfs(i, x):
    if i == N:
        return x == 0
    res = False
    for k in range(K):
        res |= dfs(i + 1, x ^ T[i][k])
    return res


if dfs(0, 0):
    print("Found")
else:
    print("Nothing")
