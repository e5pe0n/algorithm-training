A, B = map(int, input().split())


def prime_factorize(n):
    res = []
    for i in range(2, int(n**0.5) + 1):
        if n % i != 0:
            continue
        res.append(i)
        while n % i == 0:
            n //= i
    if n > 1:
        res.append(n)
    return res


D_A = prime_factorize(A)
D_B = prime_factorize(B)
T = set()
for D in (D_A, D_B):
    for d in D:
        if A % d == 0 and B % d == 0:
            T.add(d)
print(len(T) + 1)
