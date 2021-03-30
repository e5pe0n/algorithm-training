import random
from math import gcd


def pollard_rho(n):
    itr = 200
    x = int(random.uniform(0, n - 1))
    y = x
    k = 2
    res = set()
    for i in range(itr):
        x = ((x * x - 1) + n) % n
        d = gcd(((y - x) + n) % n, n)
        if d != 1 and d != n:
            res.add(d)
        if i == k:
            y = x
            k *= 2
    return list(res)


for i in range(10):
    print(pollard_rho(1387))
