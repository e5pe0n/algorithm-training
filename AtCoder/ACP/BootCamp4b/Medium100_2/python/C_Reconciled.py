MOD = 10**9 + 7


def f(n):
    res = 1
    for i in range(1, n + 1):
        res = res * i % MOD
    return res


N, M = map(int, input().split())
if N > M:
    N, M = M, N
res = 0
if M - N <= 1:
    res = f(N) * f(M) % MOD
    if M == N:
        res = res * 2 % MOD
print(res)
