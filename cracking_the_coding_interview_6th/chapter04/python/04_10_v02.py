# Cracking the Coding Interview p.266
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


def make_bt(root: int, node_idxs: List[int], edges: List[Tuple[int, int, str]]) -> Tree:
    nodes = {x: Node(x) for x in node_idxs}
    for u, v, c in edges:
        if c == 'l':
            nodes[u].left = nodes[v]
        else:
            nodes[u].right = nodes[v]
    return Tree(nodes[root])


def get_order_string(node: Node, ss: List[str]) -> None:
    if node is None:
        ss.append("X")
        return
    ss.append(f"{node.x} ")
    get_order_string(node.left, ss)
    get_order_string(node.right, ss)


def contains_tree(t1: Tree, t2: Tree) -> bool:
    ss1, ss2 = [], []
    get_order_string(t1.root, ss1)
    get_order_string(t2.root, ss2)
    s1 = "".join(ss1)
    s2 = "".join(ss2)
    return s1.find(s2) != -1


def ns(f):
    return next(f).strip()


def parse(line: str) -> Tuple[int, int, str]:
    x, y, z = line.split(' ')
    return (int(x), int(y), z)


def read_args(fp: str) -> Tuple[Tuple[int, List[int], List[Tuple[int, int, str]]]]:
    with open(fp) as f:
        n, a = map(int, ns(f).split())
        node_idxs1 = list(map(int, ns(f).split()))
        edges1 = [parse(ns(f)) for _ in range(n - 1)]
        m, b = map(int, ns(f).split())
        node_idxs2 = list(map(int, ns(f).split()))
        edges2 = [parse(ns(f)) for _ in range(m - 1)]
    return ((a, node_idxs1, edges1), (b, node_idxs2, edges2))


def solve(fp: str) -> None:
    print(f"# {fp}")
    args1, args2 = read_args(fp)
    t1 = make_bt(*args1)
    t2 = make_bt(*args2)
    print(contains_tree(t1, t2))
    print()


solve("../testcases/04_10/01.txt")
solve("../testcases/04_10/02.txt")
solve("../testcases/04_10/03.txt")
solve("../testcases/04_10/04.txt")
solve("../testcases/04_10/05.txt")
solve("../testcases/04_10/06.txt")
solve("../testcases/04_10/07.txt")
solve("../testcases/04_10/08.txt")
solve("../testcases/04_10/09.txt")

# # ../testcases/04_10/01.txt
# True

# # ../testcases/04_10/02.txt
# True

# # ../testcases/04_10/03.txt
# True

# # ../testcases/04_10/04.txt
# True

# # ../testcases/04_10/05.txt
# True

# # ../testcases/04_10/06.txt
# False

# # ../testcases/04_10/07.txt
# False

# # ../testcases/04_10/08.txt
# False

# # ../testcases/04_10/09.txt
# False
