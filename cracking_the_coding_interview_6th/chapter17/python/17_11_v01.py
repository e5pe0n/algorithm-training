from typing import List, DefaultDict
from collections import defaultdict


class DistCalculator:
    def __init__(self, words: List[int]):
        self.__word_pos_map: DefaultDict[str, List[int]] = defaultdict(list)
        for i, w in enumerate(words):
            self.__word_pos_map[w].append(i)

    def dist(self, w1: str, w2: str) -> int:
        if w1 not in self.__word_pos_map or w2 not in self.__word_pos_map:
            return -1
        idx1, idx2 = 0, 0
        pos1, pos2 = map(lambda x: self.__word_pos_map.get(x), (w1, w2))
        d = float("inf")
        while idx1 < len(pos1) and idx2 < len(pos2):
            d = min(d, abs(pos1[idx1] - pos2[idx2]))
            if pos1[idx1] < pos2[idx2]:
                idx1 += 1
            else:
                idx2 += 1
        return d


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        words = [ns(f) for _ in range(n)]
        m = int(ns(f))
        pairs = [ns(f).split() for _ in range(m)]
    dc = DistCalculator(words)
    for w1, w2 in pairs:
        print(f"d({w1}, {w2})={dc.dist(w1, w2)}")
    print()


solve("../testcases/17_11/01.txt")


# # ../testcases/17_11/01.txt
# d(fixed, bake)=1
# d(jam, turkey)=15
# d(concerned, small)=99
# d(fixed, fixed)=0
