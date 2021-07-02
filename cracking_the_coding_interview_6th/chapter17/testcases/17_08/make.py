import random


def iu(a, b):
    return int(random.uniform(a, b))


lst = [(iu(120, 220), iu(30, 200)) for _ in range(50)]
for ht, wt in lst:
    print(ht, wt)
