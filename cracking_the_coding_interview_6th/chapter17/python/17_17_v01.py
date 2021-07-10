from typing import Dict, List
from collections import defaultdict


def find_pos(s: str, T: List[str]) -> Dict[str, List[int]]:
    begins = defaultdict(list)
    for i in range(len(s)):
        begins[s[i]].append(i)
    pos = defaultdict(list)
    for t in T:
        for i in begins[t[0]]:
            if t == s[i:i + len(t)]:
                pos[t].append(i)
    return pos


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        s = ns(f)
        n = int(ns(f))
        T = [ns(f) for _ in range(n)]
    print(dict(find_pos(s, T)))
    print()


solve("../testcases/17_17/01.txt")
solve("../testcases/17_17/02.txt")

# # ../testcases/17_17/01.txt
# {'is': [15], 'the': [17, 91], 'of': [25, 97], 'computer': [27], 'data': [99], 'machinelearningisthestudyofcomputeralgorithmsthatimproveautomaticallythroughexperienceandbytheuseofdat': [0]}

# # ../testcases/17_17/02.txt
# {'is': [33, 211, 336, 562, 637, 660, 678, 732, 746, 787, 951], 'of': [571, 651, 712, 759, 917, 961, 983], 'the': [46, 152, 247, 292, 310, 407, 471, 505, 558, 761, 792, 819, 839, 910, 946], 'that': [148], 'machine': [0, 250, 474, 573], 'computer': [23, 113, 200, 313, 619, 822], 'handwritten': [963]}
