MAX_P = 55_555

N = int(input())


def primes():
    is_prime = [True] * (MAX_P + 1)
    is_prime[0] = is_prime[1] = False
    res = []
    for i in range(2, MAX_P + 1):
        if is_prime[i]:
            res.append(i)
            for j in range(i + i, MAX_P + 1, i):
                is_prime[j] = False
    return res


ps = primes()
end3 = list(filter(lambda x: str(x)[-1] == '3', ps))
print(' '.join(list(map(str, end3[:N]))))
