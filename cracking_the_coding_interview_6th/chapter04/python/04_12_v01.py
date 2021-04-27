# Cracking the Coding Interview p.275
from typing import Dict


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


def inc_hash_table(d: Dict[int, int], key: int, delta: int) -> None:
    new_cnt = d.get(key, 0) + delta
    if new_cnt == 0 and key in d:
        del d[key]
    else:
        d[key] = new_cnt


def _cnt_paths_with_sum(
        node: Node,
        target_sum: int,
        running_sum: int,
        path_cnt: Dict[int, int]) -> int:
    if node is None:
        return 0

    running_sum += node.x
    sm = running_sum - target_sum
    total_paths = path_cnt.get(sm, 0)

    if running_sum == target_sum:
        total_paths += 1

    inc_hash_table(path_cnt, running_sum, 1)
    total_paths += _cnt_paths_with_sum(node.left, target_sum, running_sum, path_cnt)
    total_paths += _cnt_paths_with_sum(node.right, target_sum, running_sum, path_cnt)
    inc_hash_table(path_cnt, running_sum, -1)

    return total_paths


def cnt_paths_with_sum(tree: Tree, target_sum: int) -> int:
    return _cnt_paths_with_sum(tree.root, target_sum, 0, {})


def ns(f):
    return next(f).strip()


def solve(fp: str) -> None:
    print(f"# {fp}")
    with open(fp) as f:
        n, s, x = map(int, ns(f).split())
        s -= 1
        nodes = list(map(lambda x: Node(int(x)), ns(f).split()))
        for _ in range(n - 1):
            a, b, c = ns(f).split()
            a = int(a) - 1
            b = int(b) - 1
            if c == 'l':
                nodes[a].left = nodes[b]
            else:
                nodes[a].right = nodes[b]
    tree = Tree(nodes[s])
    print(cnt_paths_with_sum(tree, x))
    print()


solve("../testcases/04_12/01.txt")

# # ../testcases/04_12/01.txt
# 10
