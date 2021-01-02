from collections import Counter
MOD = 10**9 + 7
N = int(input())


def factorize(n, C):
    for i in range(2, int(n**0.5) + 1):
        if n % i != 0:
            continue
        while n % i == 0:
            n //= i
            C[i] += 1
    if n > 1:
        C[n] += 1


C = Counter()
for i in range(2, N + 1):
    factorize(i, C)
res = 1
for v in C.values():
    res = res * (v + 1) % MOD
print(res)
