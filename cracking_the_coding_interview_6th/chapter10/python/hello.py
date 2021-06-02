import random

lst = list(range(30))
random.shuffle(lst)
print(' '.join(list(map(str, lst))))
