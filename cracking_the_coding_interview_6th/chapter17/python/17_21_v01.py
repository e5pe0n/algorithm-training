from typing import List


INF = float('inf')


def water_amount(data: List[int]) -> int:
    water = [INF] * len(data)
    top = 0
    for i in range(len(data)):
        top = max(top, data[i])
        water[i] = min(water[i], top - data[i])
    top = 0
    for i in range(len(data) - 1, -1, -1):
        top = max(top, data[i])
        water[i] = min(water[i], top - data[i])
    return sum(water)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _ = int(ns(f))
        data = list(map(int, ns(f).split()))
    print(water_amount(data))
    print()


solve("../testcases/17_21/01.txt")
solve("../testcases/17_21/02.txt")
solve("../testcases/17_21/03.txt")
solve("../testcases/17_21/04.txt")

# # ../testcases/17_21/01.txt
# 26

# # ../testcases/17_21/02.txt
# 64

# # ../testcases/17_21/03.txt
# 101

# # ../testcases/17_21/04.txt
# 35
