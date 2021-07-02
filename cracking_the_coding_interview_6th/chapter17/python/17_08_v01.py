from typing import List


def dfs(hw: List[List[int]], idx: int, h: int, last_w: int) -> int:
    if idx == len(hw):
        return h
    res = 0
    if last_w < hw[idx][1]:
        res = dfs(hw, idx + 1, h + 1, hw[idx][1])
    return max(res, dfs(hw, idx + 1, h, last_w))


def find_max_height(hw: List[List[int]]) -> int:
    return dfs(sorted(hw), 0, 0, -1)


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
