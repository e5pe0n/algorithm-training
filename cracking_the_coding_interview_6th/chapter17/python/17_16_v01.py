from typing import Iterable


UNIT = 15
MAX_MINUTES = 10**5


def max_minutes(v: Iterable[int]) -> int:
    ms = [0] * MAX_MINUTES
    total = 0
    for _v in v:
        _v //= UNIT
        ms[total] = _v
        total += _v
    dp = [0] * (total + 2)
    for i in range(total + 1):
        if i - 1 >= 0:
            dp[i] = max(dp[i], dp[i - 1])
        _i = i + ms[i] + 1
        dp[_i] = max(dp[_i], dp[i] + ms[i])
    return dp[total + 1] * UNIT


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _ = int(ns(f))
        v = list(map(int, ns(f).split()))
    print(max_minutes(v))
    print()


solve("../testcases/17_16/01.txt")
solve("../testcases/17_16/02.txt")
solve("../testcases/17_16/03.txt")

# # ../testcases/17_16/01.txt
# 180

# # ../testcases/17_16/02.txt
# 330

# # ../testcases/17_16/03.txt
# 330
