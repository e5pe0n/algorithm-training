def ns(f):
    return next(f).strip()


with open("../testset/primality_test/test1.txt", 'r') as f:
    N = int(ns(f))


def is_prime(n):
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return n != 1


if is_prime(N):
    print("Yes")
else:
    print("No")
