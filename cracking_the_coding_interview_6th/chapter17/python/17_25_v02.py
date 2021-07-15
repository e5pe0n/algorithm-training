from __future__ import annotations
from typing import List, Iterable


class Node:
    def __init__(self):
        self.nodes: List[Node] = []
        self.terminate: bool = False

    def _insert(self, s: str, idx: int) -> None:
        if idx == len(s):
            self.terminate = True
            return
        if len(self.nodes) == 0:
            self.nodes = [Node() for _ in range(26)]
        self.nodes[ord(s[idx]) - ord('a')]._insert(s, idx + 1)

    def insert(self, s: str) -> None:
        self._insert(s, 0)

    def _search(self, s: str, idx: int) -> bool:
        if idx == len(s):
            return self.terminate
        if len(self.nodes) == 0:
            return False
        return self.nodes[ord(s[idx]) - ord('a')]._search(s, idx + 1)

    def search(self, s: str) -> bool:
        return self._search(s, 0)

    def _search_sub(self, s: str, idx: int) -> bool:
        if idx == len(s):
            return True
        if len(self.nodes) == 0:
            return False
        return self._search_sub(s, idx + 1)

    def search_sub(self, s: str) -> bool:
        return self._search_sub(s, 0)


class Trie:
    def __init__(self, init: Iterable[str]):
        self.root = Node()
        if init:
            self.insert_all(init)

    def insert(self, s: str) -> None:
        self.root.insert(s)

    def insert_all(self, words: Iterable[str]) -> None:
        for s in words:
            self.insert(s)

    def search(self, s: str) -> bool:
        return self.root.search(s)

    def search_sub(self, s: str) -> bool:
        return self.root.search_sub(s)


def sizes(words: List[str]) -> List[List[str]]:
    max_size = max(map(len, words))
    zs = [[] for _ in range(max_size + 1)]
    for s in words:
        zs[len(s)].append(s)
    return zs


def make_wr(vs: List[str], v_choices: List[str], idx: int, n: int, trie: Trie) -> List[str]:
    if idx == n:
        return vs[::]
    for choice in v_choices:
        vs.append(choice)
        is_valid = True
        for j in range(idx + 1):
            s = ''.join(map(lambda x: x[j], vs))
            if (idx < n - 1 and not trie.search_sub(s)) or (idx == n - 1 and not trie.search(s)):
                is_valid = False
                break
        if is_valid:
            r = make_wr(vs, v_choices, idx + 1, n, trie)
            if len(r):
                return r
        vs.pop()
    return []


def max_wr(words: List[str]) -> List[str]:
    trie = Trie(words)
    zs = sizes(words)
    max_z = len(zs) - 1
    max_wr_size = 0
    res = []
    for n_rows in range(1, max_z + 1):
        for n_cols in range(1, n_rows + 1):
            wr = make_wr([], zs[n_rows], 0, n_cols, trie)
            if len(wr):
                wr_size = len(wr) * len(wr[0])
                if (wr_size > max_wr_size):
                    max_wr_size = wr_size
                    res = wr
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        words = list(set([ns(f) for _ in range(n)]))
    res = max_wr(words)
    print('\n'.join(res))
    print()


solve("../testcases/17_25/01.txt")

# # ../testcases/17_25/01.txt
# apple
# goods
# every
