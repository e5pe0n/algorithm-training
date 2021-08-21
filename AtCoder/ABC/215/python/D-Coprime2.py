MAX_A = 10**5
N, M = map(int, input().split())
A = list(map(int, input().split()))
primes = [False] * (MAX_A + 1)


def factorize(n):
    global primes
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            primes[i] = True
        while n % i == 0:
            n //= i
    if n > 1:
        primes[n] = True


for a in A:
    factorize(a)
for i in range(2, M + 1):
    if primes[i]:
        for j in range(i + i, M + 1, i):
            primes[j] = True
res = [i for i in range(1, M + 1) if not primes[i]]
print(len(res))
print('\n'.join(map(str, res)))
