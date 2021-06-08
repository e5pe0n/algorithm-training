from typing import List

INF = float('inf')


def min_diff(v1: List[int], v2: List[int]) -> int:
    if not v1 or not v2:
        return INF
    v = list(map(lambda x: (x, 1), v1))
    v += list(map(lambda x: (x, 2), v2))
    v.sort()
    mi = INF
    for i in range(len(v) - 1):
        if v[i][1] != v[i + 1][1]:
            mi = min(mi, abs(v[i][0] - v[i + 1][0]))
    return mi


def ns(f):
    return next(f).strip()


def solve(fp: str):
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
