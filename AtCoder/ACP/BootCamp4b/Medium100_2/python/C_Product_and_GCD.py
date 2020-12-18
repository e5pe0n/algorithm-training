from collections import Counter
N, P = map(int, input().split())


def prime_factorize():
    global P
    res = Counter()
    for i in range(2, int(P**0.5) + 1):
        if P % i != 0:
            continue
        cnt = 0
        while P % i == 0:
            P //= i
            cnt += 1
        res[i] = cnt
    if P > 1:
        res[P] = 1
    return res


def pow(x, n):
    res = 1
    while n > 0:
        if n & 1:
            res *= x
        x *= x
        n >>= 1
    return res


M = prime_factorize()
res = 1
for k, v in M.most_common():
    if v // N > 0:
        res *= pow(k, v // N)
print(res)
