# for i in range(2, 13):
#     for j in range(1, i):
#         print(f"({i}, {j}) {i**5 - j**5}, {(i**5 - j**5) % (i - j)}")

for i in range(6, 21):
    print((i, i - 12), i ** 5 + (i - 12) ** 5, (i ** 5 - (i - 12) ** 5) % 12)


def prime_factorize(n):
    res = []
    for i in range(2, int(n ** 0.5) + 1):
        if n % i != 0:
            continue
        while n % i == 0:
            n //= i
        res.append(i)
    return res


n = 759618
print(prime_factorize(n))
