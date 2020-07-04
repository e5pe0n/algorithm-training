from itertools import combinations, combinations_with_replacement


comb = combinations([2, 1, 3], 2)
for c in list(comb):   # [(2, 1), (2, 3), (1, 3)]
    # do something
    pass

comb_r = combinations_with_replacement([2, 1, 3], 2)
for c in list(comb_r):  # [(2, 2), (2, 1), (2, 3), (1, 1), (1, 3), (3, 3)]
    # do something
    pass
