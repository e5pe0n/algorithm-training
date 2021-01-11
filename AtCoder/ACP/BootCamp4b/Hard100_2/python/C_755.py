from collections import Counter
from sys import setrecursionlimit
setrecursionlimit(10**9)
N = int(input())


def dfs(n):
    if n > N:
        return 0
    _n = n
    C = Counter()
    while _n > 0:
        C[_n % 10] += 1
        _n //= 10
    f = True
    for i in range(3, 8, 2):
        if C[i] == 0:
            f = False
    res = int(f)
    for i in range(3, 8, 2):
        res += dfs(n * 10 + i)
    return res


res = dfs(0)
print(res)
