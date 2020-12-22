def divisors(n):
    res = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            res.append(i)
            if n // i != i:
                res.append(n // i)
    res.sort()  # optional
    return res


N = 12
res = divisors(N)
print(res)
