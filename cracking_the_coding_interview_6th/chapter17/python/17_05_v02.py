from typing import List, Tuple


def compute_deltas(s: str) -> List[int]:
    deltas = [0] * len(s)
    d = 0
    for i in range(len(s)):
        if s[i].isalpha():
            d += 1
        else:
            d -= 1
        deltas[i] = d
    return deltas


def find_longest_match(deltas: List[int]) -> Tuple[int, int]:
    m = {0: -1}
    left, right = 0, 0
    for i in range(len(deltas)):
        if deltas[i] not in m:
            m[deltas[i]] = i
        else:
            fst = m[deltas[i]]
            dist = i - fst
            longest = right - left
            if longest < dist:
                left = fst
                right = i
    return (left, right)


def find_longest_subarr(s: str) -> str:
    deltas = compute_deltas(s)
    left, right = find_longest_match(deltas)
    return s[left + 1:right + 1]


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        s = ns(f)
    res = find_longest_subarr(s)
    print(res)
    print()


solve("../testcases/17_05/01.txt")
solve("../testcases/17_05/02.txt")
solve("../testcases/17_05/03.txt")
solve("../testcases/17_05/04.txt")

# # ../testcases/17_05/01.txt
# c2de34

# # ../testcases/17_05/02.txt
# 1tu6aoi007g9

# # ../testcases/17_05/03.txt
# aaaaaaaaaa0000000000

# # ../testcases/17_05/04.txt
# a0000a000a000aaaaaaa
