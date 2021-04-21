from typing import List, Tuple


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


def make_tree(n: int, edges: List[Tuple[int, int, str]]) -> Tree:
    nodes = list(map(lambda x: Node(x), range(n)))
    for u, v, c in edges:
        if c == 'l':
            nodes[u].left = nodes[v]
        elif c == 'r':
            nodes[u].right = nodes[v]
    return Tree(nodes[0])


def dfs(node: Node) -> Tuple[int, bool]:
    if node.left is None and node.right is None:
        return (0, True)
    if node.right is None:
        height, balanced = dfs(node.left)
        return (height + 1, balanced)
    if node.left is None:
        height, balanced = dfs(node.right)
        return (height + 1, balanced)
    height_l, balanced_l = dfs(node.left)
    height_r, balanced_r = dfs(node.right)
    return (
        max(height_l, height_r) + 1,
        abs(height_l - height_r) <= 1 and balanced_l and balanced_r
    )


def is_balanced(tree: Tree) -> bool:
    if tree.root is None:
        return False
    return dfs(tree.root)[1]


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        edges = [None] * (n - 1)
        for i in range(n - 1):
            u, v, c = ns(f).split()
            edges[i] = (int(u) - 1, int(v) - 1, c)
    tree = make_tree(n, edges)
    print("balanced" if is_balanced(tree) else "unbalanced")
    print()


solve("../testcases/04_04/01.txt")
solve("../testcases/04_04/02.txt")
solve("../testcases/04_04/03.txt")
solve("../testcases/04_04/04.txt")

# # ../testcases/04_04/01.txt
# balanced

# # ../testcases/04_04/02.txt
# balanced

# # ../testcases/04_04/03.txt
# unbalanced

# # ../testcases/04_04/04.txt
# unbalanced
