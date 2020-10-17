# WA


import math


def dfs(n, i):
    if n < 9:
        return i + n // 6 + n % 6
    x6 = int(math.log(n) / math.log(6))
    x9 = int(math.log(n) / math.log(9))
    return min(dfs(n - 6 ** x6, i + 1), dfs(n - 9 ** x9, i + 1))


N = int(input())
print(dfs(N, 0))
