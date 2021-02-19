# RE: Segmentation fault
from sys import setrecursionlimit
setrecursionlimit(10**9)


MOD = 10_007
N = int(input())
memo = [0] * (N + 1)


def f(n):
    global memo
    if n == 1 or n == 2:
        return 0
    if n == 3:
        return 1
    if memo[n] > 0:
        return memo[n]
    memo[n] = ((f(n - 1) + f(n - 2)) % MOD + f(n - 3)) % MOD
    return memo[n]


print(f(N))
