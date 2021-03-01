from collections import Counter


def prime_factorize(n):
    res = Counter()
    for i in range(2, int(n ** 0.5) + 1):
        while n % i == 0:
            res[i] += 1
            n //= i
    if n > 1:
        res[n] = 1
    return res


def fact(n):
    res = 1
    for i in range(1, n + 1):
        res *= i
    return res


print(prime_factorize(fact(10)))
print(prime_factorize(fact(15)))
print(prime_factorize(fact(20)))
