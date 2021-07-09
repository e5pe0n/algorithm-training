from typing import Iterable


def max_minutes(v: Iterable[int]) -> int:
    one_away, two_away = 0, 0
    for _v in v[::-1]:
        best_with = _v + two_away
        best_without = one_away
        two_away = one_away
        one_away = max(best_with, best_without)
    return one_away


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
