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


P = [1] * (N + 1)
Q = [1] * (N + 1)
for i in range(1, N + 1):
    P[i] = P[i - 1] * i % MOD
Q[N] = inv(P[N])
for i in range(N, 0, -1):
    Q[i - 1] = Q[i] * i % MOD


def mod_com(n, k):
    if k == 0:
        return 1
    if n < 0 or k < 0 or k > n:
        return 0
    return P[n] * Q[n - k] % MOD * Q[k] % MOD


for i in range(1, K + 1):
    res = mod_com(N - K + 1, i) * mod_com(K - 1, i - 1) % MOD
    print(res)
