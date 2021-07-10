# recursion in pyton is too slow!!
from __future__ import annotations
from typing import List, Dict
from sys import setrecursionlimit
setrecursionlimit(10**6)


class Node:
    def __init__(self):
        self.nodes: Dict[str, Node] = {}
        self.idxs: List[int] = []
        self.terminate: bool = False

    def _insert(self, s: str, idx: int, cnt: int) -> None:
        self.idxs.append(idx)
        if cnt == len(s):
            self.terminate = True
            return
        if s[cnt] not in self.nodes:
            self.nodes[s[cnt]] = Node()
        self.nodes[s[cnt]]._insert(s, idx + 1, cnt + 1)

    def insert(self, s: str, idx: int) -> None:
        self._insert(s, idx, 0)

    def _search(self, s: str, cnt: int) -> List[int]:
        if cnt == len(s):
            return self.idxs
        if s[cnt] not in self.nodes:
            return {}
        return self.nodes[s[cnt]]._search(s, cnt + 1)

    def search(self, s: str) -> List[int]:
        return self._search(s, 0)


class Trie:
    def __init__(self):
        self.root = Node()

    def insert(self, s: str, idx: int) -> None:
        self.root.insert(s, idx)

    def search(self, s: str) -> List[int]:
        return self.root.search(s)


def create_trie(s: str) -> Trie:
    trie = Trie()
    for i in range(len(s)):
        trie.insert(s[i:], i)
    return trie


def search_all(s: str, T: List[str]) -> Dict[str, List[int]]:
    lookup = {}
    trie = create_trie(s)
    for t in T:
        idxs = trie.search(t)
        adjusted = list(map(lambda x: x - len(t), idxs))
        lookup[t] = adjusted
    return lookup


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        s = ns(f)
        n = int(ns(f))
        T = [ns(f) for _ in range(n)]
    print(search_all(s, T))
    print()


solve("../testcases/17_17/01.txt")
solve("../testcases/17_17/02.txt")

# # ../testcases/17_17/01.txt
# {'is': [15], 'the': [17, 91], 'of': [25, 97], 'computer': [27], 'data': [99], 'machinelearningisthestudyofcomputeralgorithmsthatimproveautomaticallythroughexperienceandbytheuseofdat': [0]}

# # ../testcases/17_17/02.txt
# {'is': [33, 211, 336, 562, 637, 660, 678, 732, 746, 787, 951], 'of': [571, 651, 712, 759, 917, 961, 983], 'the': [46, 152, 247, 292, 310, 407, 471, 505, 558, 761, 792, 819, 839, 910, 946], 'that': [148], 'machine': [0, 250, 474, 573], 'computer': [23, 113, 200, 313, 619, 822], 'handwritten': [963]}
