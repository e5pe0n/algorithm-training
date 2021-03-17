from pprint import pprint


def divisors(n):
    res = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            res.append(i)
            if n // i != i:
                res.append(n // i)
    return sorted(res)


res = {}
for i in range(2, 1000):
    divs = divisors(i)
    t = 1
    for d in divs[:-1]:
        t *= d
    if t == i:
        res[i] = divs
pprint(res)
