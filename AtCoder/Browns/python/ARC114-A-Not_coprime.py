from math import gcd
MAX_X = 50
INF = float('inf')
N = int(input())
X = list(map(int, input().split()))


def primes():
    is_prime = [True] * (MAX_X + 1)
    res = []
    for i in range(2, MAX_X + 1):
        if is_prime[i]:
            res.append(i)
            for j in range(i + i, MAX_X + 1, i):
                is_prime[j] = False
    return res


ps = primes()
res = INF
for i in range(1, 1 << len(ps)):
    t = 1
    for j in range(len(ps)):
        if i >> j & 1:
            t *= ps[j]
    f = True
    for x in X:
        if gcd(x, t) == 1:
            f = False
            break
    if f:
        res = min(res, t)
print(res)
