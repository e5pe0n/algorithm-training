from typing import List


def find_max_height(hw: List[List[int]]) -> int:
    hw = sorted(hw)
    vs = []
    res = 0
    for i in range(len(hw)):
        v = []
        for j in range(0, i):
            if vs[j][-1] < hw[i][1] and len(v) < len(vs[j]):
                v = vs[j]
        vs.append(v[:] + [hw[i][1]])
        res = max(res, len(vs[i]))
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        hw = [list(map(int, ns(f).split())) for _ in range(n)]
    print(find_max_height(hw))
    print()


solve("../testcases/17_08/01.txt")
solve("../testcases/17_08/02.txt")
solve("../testcases/17_08/03.txt")

# # ../testcases/17_08/01.txt
# 6

# # ../testcases/17_08/02.txt
# 6

# # ../testcases/17_08/03.txt
# 1
