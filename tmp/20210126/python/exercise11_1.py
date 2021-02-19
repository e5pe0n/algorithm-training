from collections import Counter


def prime_factorize(n):
    res = Counter()
    for i in range(2, int(n**0.5) + 1):
        while n % i == 0:
            n //= i
            res[i] += 1
    if n > 1:
        res[n] += 1
    return res


print(prime_factorize(1000000).most_common())
