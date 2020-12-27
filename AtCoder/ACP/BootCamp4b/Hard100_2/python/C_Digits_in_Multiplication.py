N = int(input())


def divisors(n):
    res = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            res.append((i, n // i))
    return res


V = divisors(N)
res = 10
for x, y in V:
    res = min(res, max(len(str(x)), len(str(y))))
print(res)
