import random


n = 20
lst = sorted([int(random.uniform(0, 100)) for _ in range(n)])
print(' '.join(list(map(str, lst))))
