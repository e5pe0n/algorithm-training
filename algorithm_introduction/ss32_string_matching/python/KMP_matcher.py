from typing import List


def compute_prefix_function(P: str) -> List[int]:
    m = len(P)
    Q = [0] * m
    k = 0
    for q in range(1, m):
        while k > 0 and P[k] != P[q]:
            k = Q[k]
        if P[k] == P[q]:
            k += 1
        Q[q] = k
    return Q


def KMP_matcher(T: str, P: str):
    n = len(T)
    m = len(P)
    Q = compute_prefix_function(P)
    q = 0
    for i in range(n):
        while q > 0 and P[q] != T[i]:
            q = Q[q - 1]
        if P[q] == T[i]:
            q += 1
        if q == m:
            print('Pattern occured at shift ', i + 1 - m)
            q = Q[q - 1]


T = 'bacbababacabbcbab'
P = 'ababaca'
Q = compute_prefix_function(P)
print('Q:', Q)
KMP_matcher(T, P)

# Q: [0, 0, 1, 2, 3, 0, 1]
# Pattern occured at shift  4
