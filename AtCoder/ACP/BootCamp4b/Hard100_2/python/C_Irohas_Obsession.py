from sys import setrecursionlimit
setrecursionlimit(10**9)
INF = float('inf')
N, K = map(int, input().split())
D = set(list(map(int, input().split())))


def dfs(n):
    if n >= N:
        return n
    res = INF
    if n == 0:
        for i in range(1, 10):
            if i not in D:
                res = min(res, dfs(i))
    else:
        for i in range(10):
            if i not in D:
                res = min(res, dfs(n * 10 + i))
    return res


print(dfs(0))
