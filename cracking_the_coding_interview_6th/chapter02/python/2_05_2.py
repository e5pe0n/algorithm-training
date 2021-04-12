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


def _sum1(cur1: Node, cur2: Node, res: LinkedList) -> int:
    if cur1 is None and cur2 is None:
        return 0
    t = cur1.data + cur2.data + _sum1(cur1.nxt, cur2.nxt, res)
    res.push(t % 10)
    return t // 10


def sum1(lst1: LinkedList, lst2: LinkedList) -> LinkedList:
    clone1, clone2 = map(copy, (lst1, lst2))
    res = LinkedList()
    cur1, cur2 = clone1.head, clone2.head
    while cur1 is not None and cur2 is not None:
        cur1 = cur1.nxt
        cur2 = cur2.nxt
    while cur1 is not None:
        clone2.push(0)
        cur1 = cur1.nxt
    while cur2 is not None:
        clone1.push(0)
        cur2 = cur2.nxt
    carry = _sum1(clone1.head, clone2.head, res)
    if carry:
        res.push(carry)
    return res


class PartialSum:
    def __init__(self):
        self.sum = None
        self.carry = 0


def pad_list(lst: LinkedList, length: int):
    for _ in range(length):
        lst.push(0)


def insert_before(node: Node, data: int) -> Node:
    new_node = Node()
    new_node.data = data
    if node is not None:
        new_node.nxt = node
    return new_node


def add_list_helper(cur1: Node, cur2: Node) -> PartialSum:
    if cur1 is None and cur2 is None:
        return PartialSum()

    s = add_list_helper(cur1.nxt, cur2.nxt)
    val = s.carry + cur1.data + cur2.data

    full_res = insert_before(s.sum, val % 10)

    s.sum = full_res
    s.carry = val // 10
    return s


def sum2(lst1: LinkedList, lst2: LinkedList) -> LinkedList:
    clone1, clone2 = map(copy, (lst1, lst2))
    len1, len2 = map(len, (clone1, clone2))
    if len1 < len2:
        pad_list(clone1, len2 - len1)
    else:
        pad_list(clone2, len1 - len2)

    s = add_list_helper(clone1.head, clone2.head)

    res = LinkedList()
    if s.carry:
        res.head = insert_before(s.sum, s.carry)
    else:
        res.head = s.sum
    return res


def make_list(v: List[int]) -> LinkedList:
    lst = LinkedList()
    for _v in v:
        lst.append(_v)
    return lst


def copy(lst: LinkedList) -> LinkedList:
    clone = LinkedList()
    cur = lst.head
    while cur is not None:
        clone.append(cur.data)
        cur = cur.nxt
    return clone


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
    print("")


def ns(f):
    return next(f).strip()


with open("../testcases/2_05_2.txt") as f:
    n = int(ns(f))
    ps = [None] * n
    for i in range(n):
        m1, m2 = map(int, ns(f).split())
        v1 = list(map(int, ns(f).split()))
        v2 = list(map(int, ns(f).split()))
        ps[i] = (v1, v2)


run(sum1, "sum1", ps)
run(sum2, "sum2", ps)

# # sum1
# [6, 1, 7] + [2, 9, 5] = [9, 1, 2]
# [6, 1, 7] + [3, 9, 5] = [1, 0, 1, 2]
# [9, 7] + [9, 9, 0, 3] = [1, 0, 0, 0, 0]
# [8, 7, 9] + [5, 8, 6] = [1, 4, 6, 5]

# # sum2
# [6, 1, 7] + [2, 9, 5] = [9, 1, 2]
# [6, 1, 7] + [3, 9, 5] = [1, 0, 1, 2]
# [9, 7] + [9, 9, 0, 3] = [1, 0, 0, 0, 0]
# [8, 7, 9] + [5, 8, 6] = [1, 4, 6, 5]
