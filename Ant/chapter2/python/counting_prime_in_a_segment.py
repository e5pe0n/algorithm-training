def ns(f):
    return next(f).strip()


with open("../testset/counting_prime_in_a_segment/test2.txt", 'r') as f:
    a, b = map(int, ns(f).split())


_b = int(b ** 0.5)
is_prime_small = [True] * _b
is_prime = [True] * (b - a)


def segment_sieve(a, b):
    global is_prime_small, is_prime
    for i in range(2, _b):
        if is_prime_small[i]:
            for j in range(i * 2, _b, i):
                is_prime_small[j] = False
            for j in range(max(2, (a + i - 1) // i * i), b, i):
                is_prime[j - a] = False


segment_sieve(a, b)
print(len(list(filter(lambda x: x, is_prime))))
