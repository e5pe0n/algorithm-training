from typing import List


def validate(v: List[int], candidate: int) -> bool:
    return len(list(filter(lambda x: x == candidate, v))) > len(v) // 2


def get_candidate(v: List[int]) -> int:
    majority = 0
    cnt = 0
    for _v in v:
        if cnt == 0:
            majority = _v
        if _v == majority:
            cnt += 1
        else:
            cnt -= 1
    return majority


def find_majority_elem(v: List[int]) -> int:
    candidate = get_candidate(v)
    return candidate if validate(v, candidate) else -1


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _ = int(ns(f))
        v = list(map(int, ns(f).split()))
    print(find_majority_elem(v))
    print()


solve("../testcases/17_10/01.txt")
solve("../testcases/17_10/02.txt")
solve("../testcases/17_10/03.txt")
solve("../testcases/17_10/04.txt")
solve("../testcases/17_10/05.txt")


# # ../testcases/17_10/01.txt
# 5

# # ../testcases/17_10/02.txt
# -1

# # ../testcases/17_10/03.txt
# 2

# # ../testcases/17_10/04.txt
# 1000000000

# # ../testcases/17_10/05.txt
# 5
