# https://www.geeksforgeeks.org/data-structures/linked-list/
from typing import Callable
from collections import namedtuple


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


def detect_loop1(lst: LinkedList) -> Node:
    if (lst.head is None or lst.head.nxt is None):
        return None

    slow = lst.head
    fast = slow.nxt
    while slow is not fast:
        if fast is None or fast.nxt is None:
            return None
        slow = slow.nxt
        fast = fast.nxt.nxt

    loop_len = 1
    fast = fast.nxt
    while slow is not fast:
        fast = fast.nxt
        loop_len += 1

    slow = lst.head
    fast = slow
    for _ in range(loop_len):
        fast = fast.nxt
    while slow is not fast:
        slow = slow.nxt
        fast = fast.nxt
    return slow


def detect_loop2(lst: LinkedList) -> Node:
    slow = lst.head
    fast = lst.head

    while fast is not None and fast.nxt is not None:
        slow = slow.nxt
        fast = fast.nxt.nxt
        if slow is fast:
            break

    if fast is None or fast.nxt is None:
        return None

    slow = lst.head
    while slow is not fast:
        slow = slow.nxt
        fast = fast.nxt
    return fast


def make_list() -> LinkedList:
    lst = LinkedList()
    for i in range(10):
        lst.append(i)
    return lst


def make_loop_list1() -> LinkedList:
    lst = LinkedList()
    lst.head = Node()
    lst.head.data = 0
    cur = lst.head
    for i in range(1, 10):
        if i == 5:
            mid = cur
        new_node = Node()
        new_node.data = i
        cur.nxt = new_node
        cur = cur.nxt
    cur.nxt = mid
    return lst


def make_loop_list2() -> LinkedList:
    lst = LinkedList()
    lst.head = Node()
    lst.head.data = 0
    lst.head.nxt = lst.head
    return lst


def make_loop_list3() -> LinkedList:
    lst = LinkedList()
    lst.head = Node()
    lst.head.data = 0
    new_node = Node()
    new_node.data = 1
    new_node.nxt = lst.head
    lst.head.nxt = new_node
    return lst


def run(f: Callable[[LinkedList], Node], fn: str):
    Res = namedtuple("Res", ("detected", "data"))

    def parse_res(res: Node):
        if res is None:
            return Res("false", -1)
        else:
            return Res("true", res.data)

    def p(name, res):
        print("'{}' has loop: {}, start at: {}".format(name, *res))

    print(f"# {fn}")
    lst = make_list()
    res = parse_res(f(lst))
    p("lst", res)

    loop_lst1 = make_loop_list1()
    res1 = parse_res(f(loop_lst1))
    p("loop_lst1", res1)

    loop_lst2 = make_loop_list2()
    res2 = parse_res(f(loop_lst2))
    p("loop_lst2", res2)

    loop_lst3 = make_loop_list3()
    res3 = parse_res(f(loop_lst3))
    p("loop_lst3", res3)

    print()


run(detect_loop1, "detect_loop1")
run(detect_loop2, "detect_loop2")

# # detect_loop1
# 'lst' has loop: false, start at: -1
# 'loop_lst1' has loop: true, start at: 4
# 'loop_lst2' has loop: true, start at: 0
# 'loop_lst3' has loop: true, start at: 0

# # detect_loop2
# 'lst' has loop: false, start at: -1
# 'loop_lst1' has loop: true, start at: 4
# 'loop_lst2' has loop: true, start at: 0
# 'loop_lst3' has loop: true, start at: 0
