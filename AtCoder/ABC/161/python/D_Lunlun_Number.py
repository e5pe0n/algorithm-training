# this code works in Python3.8.2 but causes RE in PyPy3.
# Do not use PyPy3 if you use recursive function.
from sys import setrecursionlimit
setrecursionlimit(10**9)
K = int(input())


cnt = 0


def dfs(n, k):
    global cnt
    res = 0
    if len(n) >= k:
        cnt += 1
        if cnt == K:
            res = int(n)
        else:
            res = 0
        return res
    if len(n) == 0:
        for i in range(1, 10):
            res += dfs(str(i), k)
        return res
    last = int(n[-1])
    for i in range(max(0, last - 1), min(9, last + 1) + 1):
        res += dfs(n + str(i), k)
    return res


for k in range(1, 1000):
    if (res := dfs("", k)):
        print(res)
        exit()
