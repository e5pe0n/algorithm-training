from collections import Counter
MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))


def factorize(n):
    res = Counter()
    for i in range(2, int(n ** 0.5) + 1):
        if n % i != 0:
            continue
        cnt = 0
        while n % i == 0:
            n //= i
            cnt += 1
        res[i] = cnt
    if n > 1:
        res[n] = 1
    return res


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


C = Counter()
for a in A:
    D = factorize(a)
    for k, v in D.most_common():
        C[k] = max(C[k], v)
lcm = 1
for k, v in C.most_common():
    lcm = lcm * mod_pow(k, v) % MOD
res = 0
for a in A:
    res = (res + lcm * inv(a) % MOD) % MOD
print(res)
