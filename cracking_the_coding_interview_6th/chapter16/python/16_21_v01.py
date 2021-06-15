from typing import List, Tuple, Union


def find_pair(v1: List[int], v2: List[int]) -> Union[Tuple[int, int], None]:
    s1 = sum(v1)
    s2 = sum(v2)
    s = set(map(lambda x: s2 - 2 * x, v2))
    for n in v1:
        if s1 - 2 * n in s:
            return (n, (s2 - (s1 - 2 * n)) // 2)
    return None


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n1, n2 = map(int, ns(f).split())
        v1 = list(map(int, ns(f).split()))
        v2 = list(map(int, ns(f).split()))
    if res := find_pair(v1, v2):
        print(f"found: {res}")
    else:
        print("not found")
    print()


solve("../testcases/16_21/01.txt")
solve("../testcases/16_21/02.txt")
solve("../testcases/16_21/03.txt")

# # ../testcases/16_21/01.txt
# found: (4, 6)

# # ../testcases/16_21/02.txt
# not found

# # ../testcases/16_21/03.txt
# found: (3, -5)
