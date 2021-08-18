from sys import setrecursionlimit
setrecursionlimit(10**9)


N = int(input())


def dfs(left, right, s):
    if left == 0 and right == 0:
        print(s)
        return
    if left > 0:
        dfs(left - 1, right, s + '(')
    if right > left:
        dfs(left, right - 1, s + ')')


if N % 2 == 0:
    dfs(N // 2, N // 2, '')
