from __future__ import annotations
from typing import TypeVar, Tuple

T = TypeVar('T')


class BiNode:
    def __init__(
        self,
        value: T = None,
        node1: BiNode[T] = None,
        node2: BiNode[T] = None
    ):
        self.value = value
        self.node1 = node1
        self.node2 = node2


def repr_bt(root: BiNode[T]) -> str:
    if root is None:
        return "null"
    return f"({repr_bt(root.node1)} {root.value} {repr_bt(root.node2)})"


def repr_dll(node: BiNode[T]) -> str:
    start = node
    res = [f"({node.node1.value} {node.value} {node.node2.value})"]
    node = node.node2
    while node is not start:
        res.append(f"({node.node1.value} {node.value} {node.node2.value})")
        node = node.node2
    return "[" + ", ".join(res) + "]"


def _bt2dll(node: BiNode[T]) -> Tuple[BiNode[T], BiNode[T]]:
    if node is None:
        return (None, None)
    left_head, left_tail = _bt2dll(node.node1)
    right_head, right_tail = _bt2dll(node.node2)
    if left_head and right_head:
        left_tail.node2 = node
        node.node1 = left_tail
        node.node2 = right_head
        right_head.node1 = node
        right_tail.node2 = left_head
        left_head.node1 = right_tail
        return (left_head, right_tail)
    elif left_head:
        left_tail.node2 = node
        node.node1 = left_tail
        node.node2 = left_head
        left_head.node1 = node
        return (left_head, node)
    elif right_head:
        node.node2 = right_head
        right_head.node1 = node
        right_tail.node2 = node
        node.node1 = right_tail
        return (node, right_head)
    else:
        return (node, node)


def bt2dll(root: BiNode[T]) -> None:
    _bt2dll(root)


def ns(f):
    return next(f).strip()


def solve(fp: str):
    print(f"# {fp}")
    with open(fp) as f:
        n = int(ns(f))
        nodes = [BiNode() for _ in range(n)]
        for i in range(n):
            value, left, right = map(int, ns(f).split())
            nodes[i].value = value
            if left > 0:
                nodes[i].node1 = nodes[left - 1]
            if right > 0:
                nodes[i].node2 = nodes[right - 1]
    print(repr_bt(nodes[0]))
    bt2dll(nodes[0])
    print(repr_dll(nodes[0]))
    print()


solve("../testcases/17_12/01.txt")

# # ../testcases/17_12/01.txt
# (((null 1 null) 2 ((null 3 null) 4 (null 5 null))) 6 (((null 7 (null 8 null)) 9 null) 10 ((null 11 null) 12 (null 13 null))))
# [(5 6 7), (6 7 8), (7 8 9), (8 9 10), (9 10 11), (10 11 12), (11 12 13), (12 13 1), (13 1 2), (1 2 3), (2 3 4), (3 4 5), (4 5 6)]
