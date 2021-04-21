from typing import List


class Node:
    def __init__(
        self,
        x: int,
        left=None,   # Node
        right=None   # Node
    ):
        self.x = x
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return f"({self.left} {self.x} {self.right})"


class Tree:
    def __init__(self, root: Node):
        self.root = root

    def __repr__(self) -> str:
        return repr(self.root)


def rec(v: List[int], left: int, right: int) -> Node:
    if right - left == 0:
        return None
    if right - left == 1:
        return Node(v[left])
    mid = (left + right) // 2
    lc = rec(v, left, mid)
    rc = rec(v, mid + 1, right)
    return Node(v[mid], lc, rc)


def make_min_bst(v: List[int]) -> Tree:
    return Tree(rec(v, 0, len(v)))


def ns(f):
    return next(f).strip()


def solve(fp: str):
    with open(fp) as f:
        _ = int(ns(f))
        v = list(map(int, ns(f).split()))
    res = make_min_bst(v)
    print(res)


solve("../testcases/04_02/01.txt")
solve("../testcases/04_02/02.txt")
solve("../testcases/04_02/03.txt")
solve("../testcases/04_02/04.txt")

# (((None 1 None) 2 (None 3 None)) 4 ((None 5 None) 6 (None 7 None)))
# ((((None 1 None) 2 None) 3 (None 4 None)) 5 ((None 6 None) 7 (None 8 None)))
# ((((None 1 None) 2 None) 3 ((None 4 None) 5 None)) 6 (((None 7 None) 8 None) 9 (None 10 None)))
# ((None 1 None) 2 None)
