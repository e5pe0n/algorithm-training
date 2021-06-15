from typing import List, Tuple


def find_pairs(v: List[int], s: int) -> List[Tuple[int, int]]:
    v = sorted(v)
    left = 0
    right = len(v) - 1
    res = []
    while left < right:
        if v[left] + v[right] == s:
            res.append((v[left], v[right]))
            left += 1
            right -= 1
        else:
            if v[left] + v[right] > s:
                right -= 1
            else:
                left += 1
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, s = map(int, ns(f).split())
        v = list(map(int, ns(f).split()))
    print(find_pairs(v, s))
    print()


solve("../testcases/16_24/01.txt")
solve("../testcases/16_24/02.txt")

# # ../testcases/16_24/01.txt
# [(0, 6), (2, 4)]

# # ../testcases/16_24/02.txt
# [(-91, 47), (-63, 19), (-62, 18), (-49, 5), (-47, 3), (-45, 1), (-44, 0), (-39, -5), (-36, -8)]
