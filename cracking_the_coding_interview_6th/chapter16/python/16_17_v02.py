from typing import List


MIN = -float('inf')


class SumRange:
    def __init__(self, sm: int, left_idx: int, right_idx: int):
        self.sm: int = sm
        self.left_idx: int = left_idx
        self.right_idx: int = right_idx


def _max_sum_cross(v: List[int], low: int, mid: int, high: int) -> SumRange:
    left_sum = MIN
    sm = 0
    max_left_idx = 0
    for i in range(mid, -1, -1):
        sm += v[i]
        if sm > left_sum:
            left_sum = sm
            max_left_idx = i
    right_sum = MIN
    sm = 0
    max_right_idx = 0
    for i in range(mid + 1, high + 1, 1):
        sm += v[i]
        if sm > right_sum:
            right_sum = sm
            max_right_idx = i
    return SumRange(left_sum + right_sum, max_left_idx, max_right_idx)


def _max_sum(v: List[int], low: int, high: int) -> SumRange:
    if high == low:
        return SumRange(v[low], low, low)
    mid = (low + high) // 2
    left = _max_sum(v, low, mid)
    right = _max_sum(v, min(mid + 1, high), high)
    cross = _max_sum_cross(v, low, mid, high)
    if left.sm >= right.sm and left.sm >= cross.sm:
        return left
    elif right.sm >= left.sm and right.sm >= cross.sm:
        return right
    else:
        return cross


def max_sum(v: List[int]) -> int:
    res = _max_sum(v, 0, len(v) - 1)
    return res.sm


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        v = list(map(int, ns(f).split()))
    print(max_sum(v))
    print()


solve("../testcases/16_17/01.txt")
solve("../testcases/16_17/02.txt")
solve("../testcases/16_17/03.txt")

# # ../testcases/16_17/01.txt
# 5

# # ../testcases/16_17/02.txt
# 192

# # ../testcases/16_17/03.txt
# 225