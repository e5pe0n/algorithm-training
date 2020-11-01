from collections import Counter


def ns(f):
    return next(f).strip()


with open("../testset/primality_test/test2.txt", 'r') as f:
    N = int(ns(f))


def prime_factor(n):
    res = Counter()
    for i in range(2, int(n ** 0.5) + 1):
        while n % i == 0:
            res[i] += 1
            n //= i
    if n != 1:
        res[n] += 1
    return res


fs = prime_factor(N)
print(" ".join([f"{f[0]}^{f[1]}" for f in fs.most_common()]))
# 541^1 547^1
