from math import gcd
from collections import Counter


MOD = int(1e9) + 7


def mod_pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res = res * x % MOD
        x = x * x % MOD
        n >>= 1
    return res


N = int(input())
X = [list(map(int, input().split())) for _ in range(N)]

cnt = 0
C = Counter()
for a, b in X:
    if a == 0 and b == 0:
        cnt += 1
    elif a == 0:
        C[(0, 1)] += 1
    elif b == 0:
        C[(-1, 0)] += 1
    else:
        g = gcd(abs(a), abs(b))
        if b < 0:
            a *= -1
            b *= -1
        C[(a // g, b // g)] += 1

res = 1
D = Counter()
for (a, b), c in C.most_common():
    if D[(a, b)] > 0:
        continue
    if a >= 0:
        p2 = (-b, a)
    else:
        p2 = (b, -a)
    c2 = C[p2]
    res = res * (((mod_pow(2, c) - 1) + (mod_pow(2, c2) - 1) + 1) % MOD) % MOD
    D[p2] += 1
print((res - 1 + cnt + MOD) % MOD)
