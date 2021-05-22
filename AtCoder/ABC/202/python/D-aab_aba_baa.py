A, B, K = map(int, input().split())

res = []


def com(n, k):
    if k == 0:
        return 1
    if k < 0:
        return 0
    res = 1
    for i in range(1, k + 1):
        res = res * (n - i + 1) // i
    return res


def dfs(k, a, b):
    if a == 0 and b == 0:
        return
    case_a = com(a + b - 1, a - 1)
    if k <= case_a:
        res.append('a')
        dfs(k, a - 1, b)
    else:
        res.append('b')
        dfs(k - case_a, a, b - 1)


dfs(K, A, B)
print(''.join(res))
