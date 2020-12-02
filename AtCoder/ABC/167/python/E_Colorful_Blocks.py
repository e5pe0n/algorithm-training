MOD = 998244353


N, M, K = map(int, input().split())


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


res = M * mod_pow(M - 1, N - 1) % MOD
x = 1
y = 1
for k in range(1, K + 1):
    x = x * (N - k) % MOD
    y = y * k % MOD
    res = (res + M * x % MOD * mod_pow(y, MOD - 2) % MOD * mod_pow(M - 1, N - 1 - k) % MOD) % MOD
print(res)
