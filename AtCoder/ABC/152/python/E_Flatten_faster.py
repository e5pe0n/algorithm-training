# O (A log log A + N log A)
from collections import Counter
MOD = 10**9 + 7
MAX_A = 10**6
N = int(input())
A = list(map(int, input().split()))

is_prime = [True] * (MAX_A + 1)
min_factor = [-1] * (MAX_A + 1)


# A loglog A
def sieve():
    for i in range(2, MAX_A + 1):
        if is_prime[i]:
            min_factor[i] = i
            for j in range(i + i, MAX_A + 1, i):
                is_prime[j] = False
                if min_factor[j] == -1:
                    min_factor[j] = i


# log A
def factorize(n):
    res = Counter()
    while n != 1:
        p = min_factor[n]
        cnt = 0
        while min_factor[n] == p:
            cnt += 1
            n //= p
        res[p] = cnt
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


sieve()
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
