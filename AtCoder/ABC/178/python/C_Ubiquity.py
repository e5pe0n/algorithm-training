MOD = int(1e9) + 7
N = int(input())


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


res = mod_pow(10, N) - 2 * mod_pow(9, N) + mod_pow(8, N)
res %= MOD
res = (res + MOD) % MOD
print(res)
