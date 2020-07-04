from itertools import permutations

perm = permutations([1, 2, 3])
print(type(perm))   # <class 'itertools.permutations'>
print(list(perm))   # [(1, 2, 3), (1, 3, 2), (2, 1, 3), (2, 3, 1), (3, 1, 2), (3, 2, 1)]

for p in list(perm):
    print(p)
