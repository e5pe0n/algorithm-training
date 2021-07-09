from typing import List
import random


class PartitionRes:
    def __init__(self, left_size: int, mid_size: int):
        self.left_size: int = left_size
        self.mid_size: int = mid_size


def partition(v: List[int], start: int, end: int, pivot: int) -> PartitionRes:
    left = start
    right = end
    mid = start
    while mid <= right:
        if v[mid] < pivot:
            v[mid], v[left] = v[left], v[mid]
            mid += 1
            left += 1
        elif v[mid] > pivot:
            v[mid], v[right] = v[right], v[mid]
            right -= 1
        else:
            mid += 1
    return PartitionRes(left - start, right - left + 1)


def _get_elem_by_rnk(v: List[int], k: int, start: int, end: int) -> int:
    pivot = v[int(random.uniform(start, end + 1))]
    p = partition(v, start, end, pivot)
    left_size, mid_size = p.left_size, p.mid_size
    if k < left_size:
        return _get_elem_by_rnk(v, k, start, start + left_size - 1)
    elif k < left_size + mid_size:
        return pivot
    else:
        return _get_elem_by_rnk(v, k - left_size - mid_size, start + left_size + mid_size, end)


def get_elem_by_rnk(v: List[int], k: int) -> int:
    if k >= len(v):
        raise ValueError("k must be less than len(v)")
    return _get_elem_by_rnk(v, k, 0, len(v) - 1)


def smallest_k(v: List[int], k: int) -> List[int]:
    if k <= 0 or k > len(v):
        raise ValueError("k must be in (0, len(v))")
    threshold = get_elem_by_rnk(v, k - 1)
    smallest = list(filter(lambda x: x < threshold, v))
    return smallest + [threshold] * (k - len(smallest))


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, k = map(int, ns(f).split())
        v = list(map(int, ns(f).split()))
    res = smallest_k(v, k)
    print(sorted(res))
    print()


solve("../testcases/17_14/01.txt")
solve("../testcases/17_14/02.txt")
solve("../testcases/17_14/03.txt")
solve("../testcases/17_14/04.txt")

# # ../testcases/17_14/01.txt
# [-5, -2, -1]

# # ../testcases/17_14/02.txt
# [-9, -7, -7, -3, -2, 0, 1, 3, 5, 6]

# # ../testcases/17_14/03.txt
# [-6, -6, -5, -5, -4, -4, -2, -1, -1, -1, 0, 0, 2, 3, 3, 4, 4, 4, 8, 8, 9, 11, 12, 12, 13, 13, 16, 16, 17, 17, 18, 21, 22, 23, 23, 24, 24, 24, 24, 25, 26, 28, 28, 29, 30, 31, 32, 33, 35, 40, 41, 41, 42, 43, 48, 49, 49, 50, 51, 51, 55, 55, 57, 58, 59, 59, 59, 61, 62, 62, 63, 64, 65, 65, 66, 67, 67, 68, 68, 70, 71, 71, 72, 75, 75, 75, 77, 77, 77, 78, 78, 79, 79, 80, 80, 80, 81, 83, 87, 89]

# # ../testcases/17_14/04.txt
# [0, 0, 0]
