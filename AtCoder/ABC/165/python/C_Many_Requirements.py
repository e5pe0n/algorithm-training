N, M, Q = map(int, input().split())
X = [list(map(int, input().split())) for _ in range(Q)]
A = [1] * N


def dfs(i):
    res = 0
    if i == N:
        for a, b, c, d in X:
            if A[b - 1] - A[a - 1] == c:
                res += d
        return res
    for j in range(A[i - 1], M + 1):
        A[i] = j
        res = max(res, dfs(i + 1))
    return res


print(dfs(1))
