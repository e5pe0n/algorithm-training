from typing import List
import random


def pick_m_iteratively(org: List[int], m: int) -> List[int]:
    if len(org) < m:
        return []
    subset = org[:m].copy()
    for i in range(m, len(org)):
        x = int(random.uniform(0, i + 1))
        if x < m:
            subset[x] = org[i]
    return subset


v = [-9, -8, -7, -7, -6, -5, -5, -4, -3, -2, -2, -1, 0, 0, 0,
     1,  2,  3,  3,  4,  5,  5,  6,  6,  6,  7,  8,  8, 9, 9]
for i in range(5):
    print(pick_m_iteratively(v, 5))
