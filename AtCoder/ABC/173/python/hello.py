from itertools import permutations

lst = [1, 1, 1, 1]
perm = permutations(lst, 1)
for p in perm:
    print(p)
