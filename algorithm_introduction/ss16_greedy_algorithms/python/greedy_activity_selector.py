from typing import List


s = [1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12]
f = [4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16]


def greedy_activity_selector(s: List[int], f: List[int]) -> List[int]:
    A = [0]
    k = 0
    for m in range(1, len(s)):
        if s[m] > f[k]:
            A.append(m)
            k = m
    return A


A = greedy_activity_selector(s, f)
print(A)    # [0, 3, 7, 10]
