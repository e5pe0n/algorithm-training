import random


def sign():
    return 1 if int(random.uniform(0, 2)) else -1


lst = [sign() * int(random.uniform(0, 10)) for _ in range(40)]
a = lst[:20]
b = lst[20:]
print(' '.join(list(map(str, a))))
print(' '.join(list(map(str, b))))
