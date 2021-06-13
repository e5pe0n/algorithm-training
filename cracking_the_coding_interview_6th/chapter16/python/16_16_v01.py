from typing import List, Tuple


def find_unsorted_range(v: List[int]) -> Tuple[int, int]:
    left = -1
    right = -1
    ma = v[0]
    for i in range(len(v)):
        if v[i] < ma:
            right = i
            if left == -1:
                left = i
            while left > 0 and v[left - 1] > v[i]:
                left -= 1
        else:
            ma = v[i]
    return (left, right)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        v = list(map(int, ns(f).split()))
    left, right = find_unsorted_range(v)
    print(left, right)
    print()


solve("../testcases/16_16/01.txt")
solve("../testcases/16_16/02.txt")
solve("../testcases/16_16/03.txt")
solve("../testcases/16_16/04.txt")

# # ../testcases/16_16/01.txt
# 3 9

# # ../testcases/16_16/02.txt
# 6 14

# # ../testcases/16_16/03.txt
# -1 -1

# # ../testcases/16_16/04.txt
# -1 -1
