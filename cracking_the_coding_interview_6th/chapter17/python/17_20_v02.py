from typing import List
from heapq import heapify, heappop, heappush


class MedianMaintainer:
    def __init__(self):
        self.smaller: List[int] = []
        self.larger: List[int] = []
        heapify(self.smaller)
        heapify(self.larger)

    @property
    def median(self) -> float:
        if len(self.smaller) == len(self.larger):
            return (-self.smaller[0] + self.larger[0]) / 2
        elif len(self.smaller) > len(self.larger):
            return -self.smaller[0]
        else:
            return self.larger[0]

    def push(self, arr: List[int]) -> None:
        for v in arr:
            heappush(self.larger, v)
        while len(self.smaller) < len(self.larger):
            heappush(self.smaller, -heappop(self.larger))


def medians(arrs: List[List[int]]) -> List[int]:
    mm = MedianMaintainer()
    res = []
    for arr in arrs:
        mm.push(arr)
        res.append(mm.median)
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n_rounds = int(ns(f))
        _ = list(map(int, ns(f).split()))
        arrs = [list(map(int, ns(f).split())) for _ in range(n_rounds)]
    print(medians(arrs))
    print()


solve("../testcases/17_20/01.txt")
solve("../testcases/17_20/02.txt")
solve("../testcases/17_20/03.txt")
solve("../testcases/17_20/04.txt")
solve("../testcases/17_20/05.txt")

# # ../testcases/17_20/01.txt
# [7.0, 6.5, 5.5]

# # ../testcases/17_20/02.txt
# [0.0, 1.5, -1.0]

# # ../testcases/17_20/03.txt
# [0.0, 0, 0]

# # ../testcases/17_20/04.txt
# [12.5, 19.5, 15.5]

# # ../testcases/17_20/05.txt
# [13.5, 20.5, 29.0]
