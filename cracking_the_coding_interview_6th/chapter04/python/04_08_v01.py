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


def _get_node(node: Node, node_idx: int) -> Node:
    if node is None:
        return None
    if node.x == node_idx:
        return node
    res_l = _get_node(node.left, node_idx)
    if res_l:
        return res_l
    res_r = _get_node(node.right, node_idx)
    if res_r:
        return res_r
    return None


def get_node(tree: Tree, node_idx: int) -> Node:
    return _get_node(tree.root, node_idx)


def dfs(node: Node, s: Node, t: Node) -> Tuple[Node, bool]:
    if node is None:
        return (None, False)
    if node is s or node is t:
        return (None, True)
    res_l = dfs(node.left, s, t)
    if res_l[0]:
        return res_l
    res_r = dfs(node.right, s, t)
    if res_r[0]:
        return res_r
    if res_l[1] and res_r[1]:
        return (node, True)
    return (None, res_r[1] or res_l[1])


def search_first_common_ancestor(tree: Tree, s: Node, t: Node) -> Node:
    ans, _ = dfs(tree.root, s, t)
    return ans


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, s, t = map(int, ns(f).split())
        s -= 1
        t -= 1
        edges = [None] * (n - 1)
        for i in range(n - 1):
            u, v, c = ns(f).split()
            edges[i] = (int(u) - 1, int(v) - 1, c)
    tree = make_tree(n, edges)
    des1 = get_node(tree, s)
    des2 = get_node(tree, t)
    res = search_first_common_ancestor(tree, des1, des2)
    print(res.x + 1 if res else None)
    print()


solve("../testcases/04_08/01.txt")
solve("../testcases/04_08/02.txt")
solve("../testcases/04_08/03.txt")
solve("../testcases/04_08/04.txt")

# # ../testcases/04_08/01.txt
# 2

# # ../testcases/04_08/02.txt
# 2

# # ../testcases/04_08/03.txt
# 1

# # ../testcases/04_08/04.txt
# None
