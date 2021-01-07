MOD = 10**9 + 7
N, A, B = map(int, input().split())


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
    x = 1
    for i in range(n, n - k, -1):
        x = x * i % MOD
    y = 1
    for i in range(k, 0, -1):
        y = y * i % MOD
    return x * inv(y) % MOD


res = mod_pow(2, N) - 1
ca = mod_com(N, A)
cb = mod_com(N, B)
res = (res + MOD * 2 - ca - cb) % MOD
print(res)
