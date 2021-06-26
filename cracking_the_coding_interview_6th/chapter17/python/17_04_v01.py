from typing import List


def _find_missing(v: List, i: int) -> int:
    if len(v) == 0:
        return 0
    ones, zeros = [], []
    mask = 1 << i
    for n in v:
        if n & mask:
            ones.append(n)
        else:
            zeros.append(n)
    if len(zeros) <= len(ones):
        res = _find_missing(zeros, i + 1)
        return (res << 1) | 0
    else:
        res = _find_missing(ones, i + 1)
        return (res << 1) | 1


def find_missing(v: List) -> int:
    return _find_missing(v, 0)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _ = int(ns(f))
        v = list(map(int, ns(f).split()))
    print(find_missing(v))
    print()


solve("../testcases/17_04/01.txt")
solve("../testcases/17_04/02.txt")

# # ../testcases/17_04/01.txt
# 3

# # ../testcases/17_04/02.txt
# 47
