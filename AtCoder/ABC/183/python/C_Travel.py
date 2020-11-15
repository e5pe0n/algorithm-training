N, K = map(int, input().split())
T = [list(map(int, input().split())) for _ in range(N)]


def dfs(u, S, t):
    if S == (1 << N) - 1 and u == 0 and t == K:
        return 1
    res = 0
    for v in range(N):
        if not(S >> v & 1):
            res += dfs(v, S | 1 << v, t + T[u][v])
    return res


print(dfs(0, 0, 0))
