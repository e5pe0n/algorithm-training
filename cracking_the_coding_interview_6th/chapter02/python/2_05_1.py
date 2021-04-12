# https://www.geeksforgeeks.org/data-structures/linked-list/
from typing import List, Tuple, Callable


class Node:
    def __init__(self):
        self.data: int = -1
        self.nxt: Node = None


class LinkedList:
    def __init__(self):
        self.head: Node = None

    def __repr__(self):
        node = self.head
        lst = []
        while node is not None:
            lst.append(node.data)
            node = node.nxt
        return repr(lst)

    def __len__(self):
        cnt = 0
        cur = self.head
        while cur is not None:
            cur = cur.nxt
            cnt += 1
        return cnt

    def push(self, new_data: int):
        new_node = Node()
        new_node.data = new_data
        new_node.nxt = self.head
        self.head = new_node

    def insert_after(self, prev_node: Node, new_data: int):
        assert prev_node is not None

        new_node = Node()
        new_node.data = new_data
        new_node.nxt = prev_node.nxt
        prev_node.nxt = new_node

    def append(self, new_data: int):
        new_node = Node()
        new_node.data = new_data
        new_node.nxt = None

        if self.head is None:
            self.head = new_node
            return

        last = self.head
        while last.nxt is not None:
            last = last.nxt
        last.nxt = new_node

    def delete_node(self, key):
        tmp = self.head
        prv = None

        if tmp is not None and tmp.data == key:
            self.head = tmp.nxt
            return

        while tmp is not None and tmp.data != key:
            prv = tmp
            tmp = tmp.nxt

        if tmp is None:
            return

        prv.nxt = tmp.nxt

    def delete_node_by_pos(self, pos):
        if self.head is None:
            return

        tmp = self.head

        if pos == 0:
            self.head = tmp.nxt
            return

        for _ in range(pos - 1):
            tmp = tmp.nxt
            if tmp is None:
                return

        if tmp.nxt is None:
            return

        tmp.nxt = tmp.nxt.nxt

    def delete_list(self):
        self.head = None

    def search(self, x):
        cur = self.head
        while cur is not None:
            if cur.data == x:
                return True
            cur = cur.nxt
        return False

    def get(self, pos):
        cur = self.head
        cnt = 0
        while cur is not None:
            if cnt == pos:
                return cur.data
            cnt += 1
            cur = cur.nxt
        raise IndexError("index out of range")


def make_list(v: List[int]):
    lst = LinkedList()
    for _v in v:
        lst.append(_v)
    return lst


def copy(lst: LinkedList):
    clone = LinkedList()
    cur = lst.head
    while cur is not None:
        clone.append(cur.data)
        cur = cur.nxt
    return clone


def sum1(lst1: LinkedList, lst2: LinkedList) -> LinkedList:
    clone1 = copy(lst1)
    clone2 = copy(lst2)
    res = LinkedList()
    cur1 = clone1.head
    cur2 = clone2.head
    carry = 0
    while cur1 is not None and cur2 is not None:
        t = cur1.data + cur2.data + carry
        carry = t // 10
        res.append(t % 10)
        cur1 = cur1.nxt
        cur2 = cur2.nxt
    while cur1 is not None:
        t = cur1.data + carry
        carry = t // 10
        res.append(t % 10)
        cur1 = cur1.nxt
    while cur2 is not None:
        t = cur2.data + carry
        carry = t // 10
        res.append(t % 10)
        cur2 = cur2.nxt
    if carry:
        res.append(1)
    return res


def _sum2(cur1: Node, cur2: Node, carry: int):
    if cur1 is None and cur2 is None:
        new_head = None
        if carry:
            new_head = Node()
            new_head.data = 1
            new_head.nxt = None
        return new_head

    data1 = 0 if cur1 is None else cur1.data
    data2 = 0 if cur2 is None else cur2.data
    t = data1 + data2 + carry
    new_head = Node()
    new_head.data = t % 10
    new_head.nxt = _sum2(None if cur1 is None else cur1.nxt,
                         None if cur2 is None else cur2.nxt, t // 10)
    return new_head


def sum2(lst1: LinkedList, lst2: LinkedList) -> LinkedList:
    clone1 = copy(lst1)
    clone2 = copy(lst2)
    res = LinkedList()
    res.head = _sum2(clone1.head, clone2.head, 0)
    return res


def run(
    f: Callable[[LinkedList, LinkedList], LinkedList],
    fn: str,
    ps: List[Tuple[List[int], List[int]]]
):
    print(f"# {fn}")
    for v1, v2 in ps:
        lst1, lst2 = map(make_list, (v1, v2))
        res = f(lst1, lst2)
        print(f"{lst1} + {lst2} = {res}")
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/2_05_1.txt") as f:
    n = int(ns(f))
    ps = [None] * n
    for i in range(n):
        m1, m2 = map(int, ns(f).split())
        v1 = list(map(int, ns(f).split()))
        v2 = list(map(int, ns(f).split()))
        ps[i] = (v1, v2)

run(sum1, "sum1", ps)
run(sum2, "sum2", ps)

# sum1
# [7, 1, 6] + [5, 9, 2] = [2, 1, 9]
# [7, 1, 6] + [5, 9, 3] = [2, 1, 0, 1]
# [7, 9] + [3, 0, 9, 9] = [0, 0, 0, 0, 1]
# [9, 7, 8] + [6, 8, 5] = [5, 6, 4, 1]

# # sum2
# [7, 1, 6] + [5, 9, 2] = [2, 1, 9]
# [7, 1, 6] + [5, 9, 3] = [2, 1, 0, 1]
# [7, 9] + [3, 0, 9, 9] = [0, 0, 0, 0, 1]
# [9, 7, 8] + [6, 8, 5] = [5, 6, 4, 1]
