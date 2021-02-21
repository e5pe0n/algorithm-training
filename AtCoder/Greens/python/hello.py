from functools import cmp_to_key


def cmp_asc(x, y):
    if x < y:
        return -1
    elif x > y:
        return 1
    return 0


def cmp_dsc(x, y):
    if x < y:
        return 1
    elif x > y:
        return -1
    return 0


A = [0, 1, 2, 3, 4]
A.sort(key=cmp_to_key(cmp_dsc))
print(A)

A.sort(key=cmp_to_key(cmp_asc))
print(A)
