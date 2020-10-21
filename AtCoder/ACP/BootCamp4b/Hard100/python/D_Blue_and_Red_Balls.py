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


N, K = map(int, input().split())
for i in range(1, K + 1):
    ans = comb(N - K + 1, i) * comb(K - 1, i - 1) % MOD
    print(ans)
