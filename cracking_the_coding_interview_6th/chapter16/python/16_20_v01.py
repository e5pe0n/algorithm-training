from __future__ import annotations
from typing import List, MutableSet


class Node:
    def __make_c2d_map():
        d2c = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        c2d = {}
        for i, s in enumerate(d2c):
            for c in s:
                c2d[c] = i
        return c2d

    __c2d_map = __make_c2d_map()

    def __init__(self):
        self.__nodes: List[Node] = []
        self.__words: MutableSet[str] = set()

    @property
    def words(self) -> List[str]:
        return list(self.__words)

    def __search(self, digits: str, idx: int) -> List[str]:
        if idx == len(digits):
            return self.words
        if len(self.__nodes) == 0:
            return []
        return self.__nodes[int(digits[idx])].__search(digits, idx + 1)

    def __insert(self, s: str, idx: int) -> bool:
        if idx == len(s):
            self.__words.add(s)
            return True
        if len(self.__nodes) == 0:
            self.__nodes = [Node() for _ in range(10)]
        return self.__nodes[self.__c2d_map[s[idx]]].__insert(s, idx + 1)

    def search(self, digits: str) -> List[str]:
        return self.__search(digits, 0)

    def insert(self, s: str) -> bool:
        return self.__insert(s, 0)


class WordTree:
    def __init__(self):
        self.root: Node = Node()

    def insert(self, word: str) -> bool:
        return self.root.insert(word)

    def insert_all(self, words: List[str]) -> bool:
        res = True
        for w in words:
            res |= self.insert(w)
        return res

    def search(self, digits: str) -> List[str]:
        return self.root.search(digits)


def ns(f):
    return next(f).strip()


def solve(fp: str, wt: WordTree):
    print(f"# {fp}")
    with open(fp) as f:
        digits = ns(f)
    print(wt.search(digits))
    print()


if __name__ == "__main__":
    with open("../testcases/16_20/words.txt") as f:
        wt = WordTree()
        wt.insert_all(list(map(lambda x: x.strip(), list(f))))
    solve("../testcases/16_20/01.txt", wt)
    solve("../testcases/16_20/02.txt", wt)
    solve("../testcases/16_20/03.txt", wt)
    solve("../testcases/16_20/04.txt", wt)

# # ../testcases/16_20/01.txt
# ['tree', 'used']

# # ../testcases/16_20/02.txt
# []

# # ../testcases/16_20/03.txt
# ['machine']

# # ../testcases/16_20/04.txt
# ['effect', 'defect']
