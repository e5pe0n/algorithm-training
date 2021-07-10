from __future__ import annotations
from typing import List, Dict
from collections import defaultdict


class Node:
    def __init__(self):
        self.nodes: Dict[str, Node] = {}
        self.terminate: bool = False

    def _insert(self, s: str, idx: int) -> None:
        if idx == len(s):
            self.terminate = True
            return
        if s[idx] not in self.nodes:
            self.nodes[s[idx]] = Node()
        self.nodes[s[idx]]._insert(s, idx + 1)

    def insert(self, s: str) -> None:
        self._insert(s, 0)

    def proceed(self, c: str) -> Node:
        return self.nodes.get(c, None)


class Trie:
    def __init__(self, init: List[str] = None):
        self.root = Node()
        self.curr = self.root
        if init:
            self.insert_all(init)

    def insert(self, s: str) -> None:
        self.root.insert(s)

    def insert_all(self, v: List[str]) -> None:
        for s in v:
            self.insert(s)

    def next_node(self, c: str) -> Node:
        self.curr = self.curr.proceed(c)
        return self.curr

    def reset_curr(self) -> None:
        self.curr = self.root


def search_all(s: str, T: List[str]) -> Dict[str, List[int]]:
    trie = Trie(T)
    lookup = defaultdict(list)
    for i in range(len(s)):
        for j in range(i, len(s)):
            nxt = trie.next_node(s[j])
            if nxt is None:
                break
            if nxt and nxt.terminate:
                lookup[s[i:j + 1]].append(i)
        trie.reset_curr()
    return lookup


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        s = ns(f)
        n = int(ns(f))
        T = [ns(f) for _ in range(n)]
    print(dict(search_all(s, T)))
    print()


solve("../testcases/17_17/01.txt")
solve("../testcases/17_17/02.txt")

# # ../testcases/17_17/01.txt
# {'machinelearningisthestudyofcomputeralgorithmsthatimproveautomaticallythroughexperienceandbytheuseofdat': [0], 'is': [15], 'the': [17, 91], 'of': [25, 97], 'computer': [27], 'data': [99]}

# # ../testcases/17_17/02.txt
# {'machine': [0, 250, 474, 573], 'computer': [23, 113, 200, 313, 619, 822], 'is': [33, 211, 336, 562, 637, 660, 678, 732, 746, 787, 951], 'the': [46, 152, 247, 292, 310, 407, 471, 505, 558, 761, 792, 819, 839, 910, 946], 'that': [148], 'of': [571, 651, 712, 759, 917, 961, 983], 'handwritten': [963]}
