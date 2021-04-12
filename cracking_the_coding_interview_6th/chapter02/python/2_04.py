# https://www.geeksforgeeks.org/data-structures/linked-list/
from typing import List, Callable, Tuple


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


def partition1(lst: LinkedList, x: int) -> LinkedList:
    # unstable
    # this is equivalent to the partitino2() in 2_04.cpp
    clone = copy(lst)
    sep = Node()
    sep.data = -1
    sep.nxt = clone.head
    clone.head = sep
    runner = sep.nxt
    fst_greater = None
    while runner is not None:
        if runner.data >= x:
            if fst_greater is None:
                fst_greater = runner
        else:
            if fst_greater is None:
                sep.data, runner.data = runner.data, sep.data
                sep = sep.nxt
            else:
                fst_greater.data, runner.data = runner.data, fst_greater
                sep.data, fst_greater.data = fst_greater.data, sep.data
                fst_greater = fst_greater.nxt
                sep = sep.nxt
        runner = runner.nxt
    return clone


def partition2(lst: LinkedList, x: int) -> LinkedList:
    # stable
    clone = copy(lst)
    before_start, before_end = None, None
    after_start, after_end = None, None

    cur = clone.head
    while cur is not None:
        nxt = cur.nxt
        cur.nxt = None
        if cur.data < x:
            if before_start is None:
                before_start = cur
                before_end = before_start
            else:
                before_end.nxt = cur
                before_end = cur
        else:
            if after_start is None:
                after_start = cur
                after_end = after_start
            else:
                after_end.nxt = cur
                after_end = cur
        cur = nxt

    res = LinkedList()
    sep = Node()
    sep.data = -1
    sep.nxt = after_start
    if before_start is None:
        res.head = sep
    else:
        before_end.nxt = sep
        res.head = before_start
    return res


def partition3(lst: LinkedList, x: int) -> LinkedList:
    # unstable
    clone = copy(lst)
    cur = clone.head
    sep = Node()
    sep.data = -1
    sep.nxt = cur
    head = sep
    tail = sep

    while cur is not None:
        nxt = cur.nxt
        if cur.data < x:
            cur.nxt = head
            head = cur
        else:
            tail.nxt = cur
            tail = cur
        cur = nxt
    tail.nxt = None

    res = LinkedList()
    res.head = head
    return res


def make_list(v: List[int]) -> LinkedList:
    lst = LinkedList()
    for _v in v:
        lst.append(_v)
    return lst


def copy(lst: LinkedList) -> LinkedList:
    res = LinkedList()
    cur = lst.head
    while cur is not None:
        res.append(cur.data)
        cur = cur.nxt
    return res


def run(
    f: Callable[[LinkedList, int], LinkedList],
    fn: str,
    ps: List[Tuple[int, List[int]]]
):
    print(f"# {fn}")
    for x, v in ps:
        before = make_list(v)
        after = f(before, x)
        print(f"{x}: {before} -> {after}")
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/2_04.txt") as f:
    n = int(ns(f))
    ps = [None] * n
    for i in range(n):
        m, x = map(int, ns(f).split())
        v = list(map(int, ns(f).split()))
        ps[i] = (x, v)


run(partition1, "partition1", ps)
run(partition2, "partition2", ps)
run(partition3, "partition3", ps)
