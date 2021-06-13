import random


def sign():
    return 1 if int(random.uniform(0, 2)) else -1


n = 20
lst = [sign() * int(random.uniform(0, 100)) for _ in range(n)]
print(' '.join(list(map(str, lst))))
