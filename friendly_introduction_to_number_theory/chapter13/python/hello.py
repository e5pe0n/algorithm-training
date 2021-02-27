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


for a in range(2, 8 + 1, 2):
    for n in range(1, 16 + 1):
        ps = sorted(prime_factorize(a ** n + 1).most_common())
        print(f"{a}^{n} + 1 = {a ** n + 1} = {ps}")
    print()
