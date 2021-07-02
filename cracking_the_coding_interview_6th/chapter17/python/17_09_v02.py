from typing import List, Tuple


def rm_min(v: List[int]) -> Tuple[List[int], int]:
    mi = min(v)
    v = list(filter(lambda x: x != mi, v))
    return v, mi


def add_products(v: List[int], val: int, ps: List[int]) -> None:
    for p in ps:
        v.append(p * val)


def find_kth_mul(ps: List[int], k: int) -> int:
    if k < 0:
        return 0
    val = 1
    v = [1]
    for _ in range(k):
        v, val = rm_min(v)
        add_products(v, val, ps)
    return val


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, k = map(int, ns(f).split())
        ps = list(map(int, ns(f).split()))
    print(find_kth_mul(ps, k))
    print()


solve("../testcases/17_09/01.txt")
solve("../testcases/17_09/02.txt")
solve("../testcases/17_09/03.txt")

# # ../testcases/17_09/01.txt
# 21

# # ../testcases/17_09/02.txt
# 65536

# # ../testcases/17_09/03.txt
# 24
