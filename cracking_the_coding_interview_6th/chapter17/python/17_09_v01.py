from typing import List


def find_kth_mul(ps: List[int], k: int) -> int:
    muls = [1]
    for i in range(1, k):
        v = []
        for p in ps:
            for m in muls:
                if p * m > muls[-1]:
                    v.append(p * m)
        muls.append(min(v))
    return muls[k - 1]


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
