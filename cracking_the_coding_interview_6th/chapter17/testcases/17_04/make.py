import random

n = 101
lst = list(range(n))
random.shuffle(lst)
print(' '.join(list(map(str, lst[1:]))))
print(lst[0])
