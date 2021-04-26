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


def is_same_tree(node1: Node, node2: Node) -> bool:
    if node1 is None and node2 is None:
        return True
    if node1 is None or node2 is None:
        return False
    if node1.x != node2.x:
        return False
    return is_same_tree(node1.left, node2.left) and is_same_tree(node1.right, node2.right)


def _is_subtree(node: Node, sub_root: Node) -> bool:
    if node is None:
        return False
    if node.x == sub_root.x and is_same_tree(node, sub_root):
        return True
    if _is_subtree(node.left, sub_root):
        return True
    return _is_subtree(node.right, sub_root)


def is_subtree(tree: Tree, sub: Tree) -> bool:
    return _is_subtree(tree.root, sub.root)


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
    print(is_subtree(t1, t2))
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
