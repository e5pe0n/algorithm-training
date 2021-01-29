MOD = 10**9 + 7
N, K = map(int, input().split())
A = sorted(list(map(int, input().split())))

P = [0] * (N + 1)
Q = [0] * (N + 1)


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


def init():
    global P, Q
    P[0] = 1
    for i in range(1, N + 1):
        P[i] = P[i - 1] * i % MOD
    Q[N] = inv(P[N])
    for i in range(N, 0, -1):
        Q[i - 1] = Q[i] * i % MOD


def mod_com(n, k):
    if k < 0 or n < 0 or n < k:
        return 0
    if k == 0:
        return 1
    return P[n] * Q[n - k] % MOD * Q[k] % MOD


init()
res = 0
for i in range(K - 1, N):
    res = (res + mod_com(i, K - 1) * A[i] % MOD) % MOD
for i in range(N - K + 1):
    res = (res - mod_com(N - i - 1, K - 1) * A[i] % MOD + MOD) % MOD
print(res)
