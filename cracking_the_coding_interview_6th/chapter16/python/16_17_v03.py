from typing import List


def max_sum(v: List[int]) -> int:
    ma_sum = 0
    sm = 0
    for n in v:
        sm += n
        if ma_sum < sm:
            ma_sum = sm
        elif sm < 0:
            sm = 0
    return ma_sum


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
