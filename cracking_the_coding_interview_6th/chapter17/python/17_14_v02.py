from typing import List
from heapq import heapify, heappushpop


def find_smallest_kth_nums(v: List[int], k: int) -> List[int]:
    if len(v) <= k:
        return v
    v = list(map(lambda x: -x, v))
    q = v[:k]
    heapify(q)
    for _v in v[k:]:
        if _v > q[0]:
            heappushpop(q, _v)
    return list(map(lambda x: -x, q))


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, k = map(int, ns(f).split())
        v = list(map(int, ns(f).split()))
    res = find_smallest_kth_nums(v, k)
    print(sorted(res))
    print()


solve("../testcases/17_14/01.txt")
solve("../testcases/17_14/02.txt")
solve("../testcases/17_14/03.txt")
