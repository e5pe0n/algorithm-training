from collections import deque
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


def make_depth_list(tree: Tree) -> List[List[Node]]:
    res = []
    q = deque()
    if tree.root is None:
        return res
    res.append([tree.root])
    q.append((tree.root, 0))
    while len(q) > 0:
        par, depth = q.popleft()
        if len(res) <= depth + 1:
            res.append([])
        if par.left is not None:
            res[depth + 1].append(par.left)
            q.append((par.left, depth + 1))
        if par.right is not None:
            res[depth + 1].append(par.right)
            q.append((par.right, depth + 1))
    return list(filter(lambda x: x, res))


def show_list(lst: List[List[Node]]) -> None:
    for i, v in enumerate(lst):
        print(f"{i}: {' '.join(list(map(lambda n: str(n.x), v)))}")


def ns(f):
    return next(f).strip()


def solve(fp: str):
    with open(fp) as f:
        _ = int(ns(f))
        v = list(map(int, ns(f).split()))
    print(f"# {fp}")
    tree = make_min_bst(v)
    res = make_depth_list(tree)
    show_list(res)
    print()


solve("../testcases/04_02/01.txt")
solve("../testcases/04_02/02.txt")
solve("../testcases/04_02/03.txt")
solve("../testcases/04_02/04.txt")

# # ../testcases/04_02/01.txt
# 0: 4
# 1: 2 6
# 2: 1 3 5 7

# # ../testcases/04_02/02.txt
# 0: 5
# 1: 3 7
# 2: 2 4 6 8
# 3: 1

# # ../testcases/04_02/03.txt
# 0: 6
# 1: 3 9
# 2: 2 5 8 10
# 3: 1 4 7

# # ../testcases/04_02/04.txt
# 0: 2
# 1: 1
