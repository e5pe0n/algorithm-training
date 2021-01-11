from sys import setrecursionlimit
setrecursionlimit(10**9)
N = int(input())


def dfs(n):
    if n > N:
        return 0
    res = int(n <= N)
    for i in range(10):
        res += dfs((n // 10 * 10 + i) * 10 + n % 10)
    return res


res = 0
for i in range(1, 10):
    for j in range(i, 10):
        if i == j:
            t = int(i <= N) + dfs(i * 10 + i)
            res += t * t
        else:
            left = dfs(i * 10 + j)
            right = dfs(j * 10 + i)
            res += left * right * 2
print(res)
