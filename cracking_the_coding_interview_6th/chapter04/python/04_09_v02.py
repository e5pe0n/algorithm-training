from typing import List, Deque
from collections import deque


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


def conn_nodes(nodes: List[Node], left: int, right: int) -> Node:
    if right - left == 0:
        return None
    if right - left == 1:
        return nodes[left]
    mid = (left + right) // 2
    nodes[mid].left = conn_nodes(nodes, left, mid)
    nodes[mid].right = conn_nodes(nodes, mid + 1, right)
    return nodes[mid]


def make_bst(n: int) -> Tree:
    nodes = list(map(lambda x: Node(x), range(n)))
    return Tree(conn_nodes(nodes, 0, n))


def weave_list(fst: Deque[int], snd: Deque[int], ress: List[Deque[int]], pre: Deque[int]) -> None:
    if len(fst) == 0 or len(snd) == 0:
        ress.append(pre + fst + snd)
        return

    head_fst = fst.popleft()
    pre.append(head_fst)
    weave_list(fst, snd, ress, pre)
    pre.pop()
    fst.appendleft(head_fst)

    head_snd = snd.popleft()
    pre.append(head_snd)
    weave_list(fst, snd, ress, pre)
    pre.pop()
    snd.appendleft(head_snd)


def _all_sequences(node: Node) -> List[Deque[int]]:
    res: List[Deque[int]] = []
    if node is None:
        res.append(deque())
        return res

    pre = deque([node.x])

    left_seq = _all_sequences(node.left)
    right_seq = _all_sequences(node.right)

    for left in left_seq:
        for right in right_seq:
            weaved: List[Deque[int]] = []
            weave_list(left, right, weaved, pre)
            res += weaved
    return res


def all_sequences(tree: Tree) -> List[Deque[int]]:
    return _all_sequences(tree.root)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
    tree = make_bst(n)
    res = all_sequences(tree)
    for v in res:
        print(' '.join(list(map(lambda x: str(x + 1), v))))
    print()


solve("../testcases/04_09/01.txt")
solve("../testcases/04_09/02.txt")
solve("../testcases/04_09/03.txt")
