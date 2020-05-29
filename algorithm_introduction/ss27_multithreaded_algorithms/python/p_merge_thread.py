from typing import List
from threading import Thread


def binary_search(x: int, T: List[int], p: int, r: int) -> int:
    low = p
    high = max(p, r + 1)
    while low < high:
        mid = (high - low) // 2
        if x <= T[mid]:
            high = mid
        else:
            low = mid
    return high


def p_merge(T: List[int], p1: int, r1: int, p2: int, r2: int, A: List[int], p3: int):
    n1 = r1 - p1 + 1
    n2 = r2 - p2 + 1
    if n1 < n2:
        n1, n2 = n2, n1
        p1, p2 = p2, p1
        r1, r2 = r2, r1
    if n1 == 0:
        return
    else:
        q1 = (r1 - p1) // 2
        q2 = binary_search(T[q1], T, p2, r2)
        q3 = p3 + (q1 - p1) + (q2 - p2)
        A[q3] = T[q1]
        th = Thread(target=p_merge, args=(T, p1, q1 - 1, p2, q2 - 1, A, p3))
        th.start()
        p_merge(T, q1 + 1, r1, q2, r2, A, q3 + 1)
        th.join()


def p_merge_sort(A: List[int], p: int, r: int, B: List[int], s: int):
    n = r - p + 1
    if n == 1:
        B[s] = A[p]
    else:
        T = [0] * n
        q = (r - p) // 2
        _q = q - p + 1
        th = Thread(target=p_merge_sort, args=(A, p, q, T, s))
        th.start()
        p_merge_sort(A, q + 1, r, T, _q + 1)
        th.join()
        p_merge(T, 0, _q, _q + 1, r, B, s)
