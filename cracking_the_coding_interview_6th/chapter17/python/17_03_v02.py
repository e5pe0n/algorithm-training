from typing import List
import random


def pick_recursively(org: List[int], m: int, i: int, rand: random) -> List[int]:
    if i < m - 1:
        return []
    elif i == m - 1:
        return org[:m].copy()
    else:
        s = pick_recursively(org, m, i - 1, rand)
        x = int(rand.uniform(0, i + 1))
        if x < m:
            s[x] = org[i]
        return s


def gen_rand_set(org: List[int], m: int) -> List[int]:
    rand = random
    return pick_recursively(org, m, len(org) - 1, rand)


v = [-9, -8, -7, -7, -6, -5, -5, -4, -3, -2, -2, -1, 0, 0, 0,
     1,  2,  3,  3,  4,  5,  5,  6,  6,  6,  7,  8,  8, 9, 9]
for i in range(5):
    print(gen_rand_set(v, 5))
