from collections import defaultdict
import random


def sign():
    return 1 if int(random.uniform(0, 2)) else -1


lst = [sign() * int(random.uniform(0, 100)) for _ in range(100)]
d = defaultdict(list)
for i in range(len(lst)):
    for j in range(i + 1, len(lst)):
        d[lst[i] + lst[j]].append((lst[i], lst[j]))
print(' '.join(list(map(str, lst))))
print(d)
