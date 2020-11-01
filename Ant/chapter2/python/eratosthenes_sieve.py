def ns(f):
    return next(f).strip()


with open("../testset/eratosthenes_sieve/test2.txt", 'r') as f:
    N = int(ns(f))


primes = []
is_prime = [False, False] + [True] * (N - 1)


def sieve(n):
    global primes, is_prime
    for i in range(2, n + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i * 2, n + 1, i):
                is_prime[j] = False
    return len(primes)


res = sieve(N)
print(res)
