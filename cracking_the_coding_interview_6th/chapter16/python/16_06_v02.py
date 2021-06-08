from bisect import bisect_left
from typing import List

INF = float('inf')


def min_diff(v1: List[int], v2: List[int]) -> int:
    if not v1 or not v2:
        return INF
    if len(v1) > len(v2):
        v1, v2 = v2, v1
    v1.sort()
    mi = INF
    for n in v2:
        idx = bisect_left(v1, n)
        if idx == len(v1):
            idx -= 1
        mi = min(mi, abs(v1[idx] - n))
        if idx > 0:
            mi = min(mi, abs(v1[idx - 1] - n))
    return mi


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, m = map(int, ns(f).split())
        v1 = list(map(int, ns(f).split()))
        v2 = list(map(int, ns(f).split()))
    print(min_diff(v1, v2))
    print()


solve("../testcases/16_06/01.txt")
solve("../testcases/16_06/02.txt")
solve("../testcases/16_06/03.txt")


# # ../testcases/16_06/01.txt
# 3

# # ../testcases/16_06/02.txt
# 1

# # ../testcases/16_06/03.txt
# 1
