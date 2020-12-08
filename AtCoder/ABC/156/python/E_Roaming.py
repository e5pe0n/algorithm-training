MOD = 10**9 + 7


N, K = map(int, input().split())


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


p = [0] * (N + 1)
q = p.copy()

p[0] = 1
for i in range(1, N + 1):
    p[i] = p[i - 1] * i % MOD
q[N] = inv(p[N])
for i in range(N, 0, -1):
    q[i - 1] = q[i] * i % MOD


def comb(n, k):
    if k == 0:
        return 1
    if k < 0 or k > n:
        return 0
    return p[n] * q[n - k] % MOD * q[k] % MOD


res = 0
for i in range(min(K, N - 1) + 1):
    res = (res + comb(N, i) * comb(N - 1, N - i - 1) % MOD) % MOD
print(res)
