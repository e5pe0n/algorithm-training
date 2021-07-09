from __future__ import annotations
from typing import List, Iterable


class SearchRes:
    def __init__(self, found: bool = False, term_cnt: int = 0):
        self.found: bool = found
        self.term_cnt: int = term_cnt


class Node:
    def __init__(self):
        self.nodes: List[Node] = []
        self.terminate: bool = False

    def __chr2idx(self, c: str) -> int:
        return ord(c) - ord('a')

    def __insert(self, s: str, idx: int) -> None:
        if idx == len(s):
            self.terminate = True
            return
        if len(self.nodes) == 0:
            self.nodes = [Node() for _ in range(26)]
        self.nodes[self.__chr2idx(s[idx])].__insert(s, idx + 1)

    def __search(self, s: str, idx: int, term_cnt: int) -> SearchRes:
        if idx == len(s):
            return SearchRes(self.terminate, term_cnt + int(self.terminate))
        if len(self.nodes) == 0:
            return SearchRes()
        return self.nodes[self.__chr2idx(s[idx])] \
            .__search(s, idx + 1, term_cnt + int(self.terminate))

    def insert(self, s: str) -> None:
        self.__insert(s, 0)

    def search(self, s: str) -> SearchRes:
        return self.__search(s, 0, 0)


class Trie:
    def __init__(self, init: Iterable[str]):
        self.root = Node()
        self.insert_all(init)

    def insert(self, s: str) -> None:
        self.root.insert(s)

    def insert_all(self, v: Iterable[str]) -> None:
        for s in v:
            self.root.insert(s)

    def search(self, s: str) -> SearchRes:
        return self.root.search(s)


def longest_composite_words(v: Iterable[int]) -> str:
    trie = Trie(v)
    res = ""
    for s in v:
        if len(s) < len(res):
            continue
        search_res = trie.search(s)
        if search_res.term_cnt > 1:
            res = s
    return res


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        _ = int(ns(f))
        v = ns(f).split()
    print(longest_composite_words(v))
    print()


solve("../testcases/17_15/01.txt")
solve("../testcases/17_15/02.txt")
solve("../testcases/17_15/03.txt")
solve("../testcases/17_15/04.txt")
solve("../testcases/17_15/05.txt")

# # ../testcases/17_15/01.txt
# dogwalker

# # ../testcases/17_15/02.txt
# dogcatwalker

# # ../testcases/17_15/03.txt
# dogcatwalkerwalknanabanana

# # ../testcases/17_15/04.txt
# timeline

# # ../testcases/17_15/05.txt
# informationtechnology
