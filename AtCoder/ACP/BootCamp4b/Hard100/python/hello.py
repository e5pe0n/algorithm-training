MOD = 1_000_000_007


def comb(n, k):
    if k <= 0:
        return 1
    x = n
    for i in range(n - 1, n - k, -1):
        x *= i
    y = k
    for i in range(k - 1, 0, -1):
        y *= i
    return x // y


def mod_pow(x, n):
    ret = 1
    while n > 0:
        if n & 1:
            ret = ret * x % MOD
        x = x * x % MOD
        n >>= 1
    return ret


def mod_comb(n, k):
    if k <= 0:
        return 1
    x = n
    for i in range(n - 1, n - k, -1):
        x = x * i % MOD
    y = k
    for i in range(k - 1, 0, -1):
        y = y * i % MOD
    return x * mod_pow(y, MOD - 2) % MOD
