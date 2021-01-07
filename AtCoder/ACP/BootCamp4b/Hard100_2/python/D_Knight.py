MOD = 10**9 + 7


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


X, Y = map(int, input().split())
res = 0
if (X + Y) % 3 == 0 and abs(X - Y) <= (X + Y) // 3:
    res = mod_com((X + Y) // 3, abs((X + Y) // 3 - X))
print(res)
