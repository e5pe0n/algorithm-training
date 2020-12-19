from math import gcd


def extgcd(a, b, x, y):
    d = a
    if b != 0:
        d = extgcd(b, a % b, y, x)
        y[0] = y[0] - (a // b) * x[0]
    else:
        x[0] = 1
        y[0] = 0
    return d


T = int(input())
ans = []
for _ in range(T):
    N, S, K = map(int, input().split())
    M = N - S
    g = gcd(K, gcd(M, N))
    K, M, N = map(lambda x: x // g, (K, M, N))
    if gcd(K, N) == 1:
        _K, _ = [0], [0]
        extgcd(K, N, _K, _)
        res = _K[0] * M
        res %= N
        res = (res + N) % N
    else:
        res = -1
    ans.append(str(res))
print('\n'.join(ans))
