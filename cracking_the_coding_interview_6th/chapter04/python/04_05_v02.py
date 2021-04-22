from typing import List, Tuple


MAX = float('inf')


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


def make_tree(v: List[int], edges: List[Tuple[int, int, str]]) -> Tree:
    nodes = list(map(lambda x: Node(x), v))
    for u, v, c in edges:
        if c == 'l':
            nodes[u].left = nodes[v]
        elif c == 'r':
            nodes[u].right = nodes[v]
    return Tree(nodes[0])


def is_within_range(node: Node, lb: int, ub: int) -> bool:
    if node is None:
        return True
    return is_within_range(node.left, lb, node.x) \
        and is_within_range(node.right, node.x + 1, ub) \
        and lb <= node.x <= ub


def is_valid_bst(tree: Tree) -> bool:
    if tree.root is None:
        return False
    return is_within_range(tree.root, -MAX, MAX)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        v = list(map(int, ns(f).split()))

        def parse(x):
            return (int(x[0]) - 1, int(x[1]) - 1, x[2])
        edges = [parse(ns(f).split()) for _ in range(n - 1)]
    tree = make_tree(v, edges)
    print(is_valid_bst(tree))
    print()


solve("../testcases/04_05/01.txt")
solve("../testcases/04_05/02.txt")
solve("../testcases/04_05/03.txt")
solve("../testcases/04_05/04.txt")
solve("../testcases/04_05/05.txt")
solve("../testcases/04_05/06.txt")
solve("../testcases/04_05/07.txt")
solve("../testcases/04_05/08.txt")
solve("../testcases/04_05/09.txt")

# # ../testcases/04_05/01.txt
# True

# # ../testcases/04_05/02.txt
# False

# # ../testcases/04_05/03.txt
# True

# # ../testcases/04_05/04.txt
# False

# # ../testcases/04_05/05.txt
# True

# # ../testcases/04_05/06.txt
# False

# # ../testcases/04_05/07.txt
# True

# # ../testcases/04_05/08.txt
# False

# # ../testcases/04_05/09.txt
# False
