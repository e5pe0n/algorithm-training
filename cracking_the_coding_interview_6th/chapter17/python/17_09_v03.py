from typing import List
from collections import deque


def find_kth_mul(ps: List[int], k: int) -> int:
    if k < 0:
        return 0
    val = 0
    qs = [deque() for _ in range(len(ps))]
    qs[0].append(1)
    for _ in range(k):
        mi = qs[0][0]
        mi_idx = 0
        for i, q in enumerate(qs):
            if len(q) and mi > q[0]:
                mi = q[0]
                mi_idx = i
        val = mi
        qs[mi_idx].popleft()
        for i in range(mi_idx, len(qs)):
            qs[i].append(mi * ps[i])
    return val


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, k = map(int, ns(f).split())
        ps = list(map(int, ns(f).split()))
    print(find_kth_mul(ps, k))
    print()


solve("../testcases/17_09/01.txt")
solve("../testcases/17_09/02.txt")
solve("../testcases/17_09/03.txt")

# # ../testcases/17_09/01.txt
# 21

# # ../testcases/17_09/02.txt
# 65536

# # ../testcases/17_09/03.txt
# 24
