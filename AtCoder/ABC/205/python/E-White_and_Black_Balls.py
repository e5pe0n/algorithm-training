MOD = 10**9 + 7
N, M, K = map(int, input().split())


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


def inv(x):
    return mod_pow(x, MOD - 2)


def mod_com(n, k):
    if k < 0 or n < 0 or n < k:
        return 0
    if k == 0:
        return 1
    x = 1
    for i in range(n, n - k, -1):
        x = x * i % MOD
    y = 1
    for i in range(1, k + 1):
        y = y * i % MOD
    return x * inv(y) % MOD


if N > M + K:
    print(0)
    exit()
res = ((mod_com(N + M, N) - mod_com(N + M, M + K + 1)) % MOD + MOD) % MOD
print(res)
