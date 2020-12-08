MOD = 10**9 + 7


n, a, b = map(int, input().split())


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


def mod_comb(n, k):
    if k == 0:
        return 1
    if k < 0 or k > n:
        return 0
    x = n
    for i in range(n - 1, n - k, -1):
        x = x * i % MOD
    y = k
    for i in range(k - 1, 0, -1):
        y = y * i % MOD
    return x * mod_pow(y, MOD - 2) % MOD


al = mod_pow(2, n) - 1
case_a = mod_comb(n, a)
case_b = mod_comb(n, b)
res = (al - case_a - case_b + 2 * MOD) % MOD
print(res)
