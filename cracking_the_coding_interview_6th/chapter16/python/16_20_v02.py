from typing import List, Dict, MutableSet, Iterable
from collections import defaultdict


class WordDict:
    def __make_c2d_map() -> Dict[str, int]:
        d2c = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        c2d = {}
        for i, s in enumerate(d2c):
            for c in s:
                c2d[c] = i
        return c2d

    __c2d_map = __make_c2d_map()

    def __init__(self, init: Iterable[str]):
        self.__d2w_map: Dict[str, MutableSet[str]] = defaultdict(set)
        if init:
            self.insert_all(init)

    def __insert(self, word: str, digits: str) -> bool:
        if len(word) == len(digits):
            self.__d2w_map[digits].add(word)
            return True
        return self.__insert(word, digits + str(self.__c2d_map[word[len(digits)]]))

    def insert(self, word: str) -> bool:
        return self.__insert(word, "")

    def insert_all(self, words: Iterable[str]) -> bool:
        res = True
        for w in words:
            res |= self.insert(w)
        return res

    def search(self, digits: str) -> List[str]:
        return list(self.__d2w_map.get(digits, set()))


def ns(f):
    return next(f).strip()


def solve(fp: str, d: WordDict):
    print(f"# {fp}")
    with open(fp) as f:
        digits = ns(f)
    print(d.search(digits))
    print()


if __name__ == "__main__":
    with open("../testcases/16_20/words.txt") as f:
        d = WordDict(list(map(lambda x: x.strip(), list(f))))
    solve("../testcases/16_20/01.txt", d)
    solve("../testcases/16_20/02.txt", d)
    solve("../testcases/16_20/03.txt", d)
    solve("../testcases/16_20/04.txt", d)


# # ../testcases/16_20/01.txt
# ['tree', 'used']

# # ../testcases/16_20/02.txt
# []

# # ../testcases/16_20/03.txt
# ['machine']

# # ../testcases/16_20/04.txt
# ['defect', 'effect']
