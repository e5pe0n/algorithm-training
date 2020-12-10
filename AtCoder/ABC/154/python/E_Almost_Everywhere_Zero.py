S = input()
N = len(S)
K = int(input())


def com(n, k):
    if n <= 0 or k > n:
        return 0
    if k == 0:
        return 1
    x = n
    for i in range(n - 1, n - k, -1):
        x *= i
    y = k
    for i in range(k - 1, 0, -1):
        y *= i
    return x // y


def rec(i, k, smaller):
    if i == N:
        return int(k == 0)
    if k == 0:
        return 1
    if smaller:
        return com(N - i, k) * (9 ** k)
    else:
        if S[i] == '0':
            return rec(i + 1, k, False)
        else:
            zero = rec(i + 1, k, True)
            md = rec(i + 1, k - 1, True) * (int(S[i]) - 1)
            ub = rec(i + 1, k - 1, False)
            return zero + md + ub


print(rec(0, K, False))
