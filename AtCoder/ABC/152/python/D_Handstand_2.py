from sys import setrecursionlimit
setrecursionlimit(10**9)


N = int(input())


def dfs(n):
    if n > N:
        return 0
    res = 1
    for i in range(10):
        res += dfs((n // 10 * 100) + 10 * i + n % 10)
    return res


res = 0
for i in range(1, 10):
    for j in range(i, 10):
        if i == j and i <= N:
            cnt = dfs(i * 10 + j) + 1
            res += cnt * cnt
        else:
            cnt1 = dfs(i * 10 + j)
            cnt2 = dfs(j * 10 + i)
            res += cnt1 * cnt2 * 2
print(res)
