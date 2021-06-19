MAX_L = 10**6
L, R = map(int, input().split())


def sieve():
    is_prime = [True] * (R + 1)
    primes = []
    for i in range(2, R + 1):
        if is_prime[i]:
            primes.append(i)
            for j in range(i + i, R + 1, i):
                is_prime[j] = False
    return primes


cnt = 0
primes = sieve()
B = [False] * (R + 1)
for p in primes:
    for _p in range(p + p, R + 1):
        if B[_p]:
            cnt += 1
        B[_p] = True
print(cnt * 2)
