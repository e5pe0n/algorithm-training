from collections import Counter


def prime_factorize(n):
    res = Counter()
    for i in range(2, int(n ** 0.5) + 1):
        while n % i == 0:
            res[i] += 1
            n //= i
    if n > 1:
        res[n] += 1
    return res


def phi(n):
    factors = prime_factorize(n)
    res = n
    for k in factors.keys():
        n = n // k * (k - 1)
    return res


print(f"phi(97)={phi(97)}")  # 96
print(f"phi(8800)={phi(8800)}")  # 8800
print(f"phi(1000000)={phi(1000000)}")   # 400000
