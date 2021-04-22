from typing import List, Tuple


MAX = float('inf')


class Node:
    def __init__(
        self,
        idx: int,
        x: int,
        par=None,    # Node
        left=None,   # Node
        right=None   # Node
    ):
        self.idx = idx
        self.x = x
        self.par = par
        self.left = left
        self.right = right

    def __repr__(self) -> str:
        return f"({self.left} {self.x} {self.right})"


class Tree:
    def __init__(self, root: Node):
        self.root = root

    def __repr__(self) -> str:
        return repr(self.root)


def make_tree(v: List[int], edges: List[Tuple[int, int, str]]) -> Tree:
    nodes = list(map(lambda x: Node(x[0], x[1]), enumerate(v)))
    for u, v, c in edges:
        if c == 'l':
            nodes[u].left = nodes[v]
            nodes[v].par = nodes[u]
        elif c == 'r':
            nodes[u].right = nodes[v]
            nodes[v].par = nodes[u]
    return Tree(nodes[0])


def _get_node(node: Node, node_idx: int) -> Node:
    if not node:
        return None
    if node.idx == node_idx:
        return node
    res_l = _get_node(node.left, node_idx)
    res_r = _get_node(node.right, node_idx)
    if res_l:
        return res_l
    if res_r:
        return res_r
    return None


def get_node(tree: Tree, node_idx: int) -> Node:
    return _get_node(tree.root, node_idx)


def get_succ(tree: Tree, node_idx: int) -> Node:
    node = get_node(tree, node_idx)
    if not node:
        return None
    if node.right:
        node = node.right
        while node.left:
            node = node.left
        return node
    par = node.par
    while par and par.left is not node:
        node = par
        par = node.par
    return par


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n, k = map(int, ns(f).split())
        v = list(map(int, ns(f).split()))

        def parse(x):
            return (int(x[0]) - 1, int(x[1]) - 1, x[2])
        edges = [parse(ns(f).split()) for _ in range(n - 1)]

    tree = make_tree(v, edges)
    res = get_succ(tree, k - 1)
    print(res.idx + 1 if res else None)
    print()


solve("../testcases/04_06/01.txt")
solve("../testcases/04_06/02.txt")
solve("../testcases/04_06/03.txt")
solve("../testcases/04_06/04.txt")
solve("../testcases/04_06/05.txt")

# # ../testcases/04_06/01.txt
# 11

# # ../testcases/04_06/02.txt
# 12

# # ../testcases/04_06/03.txt
# 1

# # ../testcases/04_06/04.txt
# 6

# # ../testcases/04_06/05.txt
# None
