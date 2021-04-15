# https://www.geeksforgeeks.org/data-structures/linked-list/
from typing import Tuple, Callable


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


def forward(node: Node, cnt: int) -> Node:
    for _ in range(cnt):
        assert node is not None
        node = node.nxt
    return node


def get_intersection1(lst1: LinkedList, lst2: LinkedList) -> Node:
    len1, len2 = map(len, (lst1, lst2))

    cur1, cur2 = lst1.head, lst2.head
    if len1 < len2:
        cur2 = forward(cur2, len2 - len1)
    else:
        cur1 = forward(cur1, len1 - len2)

    while cur1 is not cur2:
        cur1 = cur1.nxt
        cur2 = cur2.nxt
    return cur1


def make_list() -> Tuple[LinkedList, LinkedList]:
    lst1 = LinkedList()
    lst2 = LinkedList()

    for i in range(10, 20):
        lst1.append(i)
    for i in range(20, 23):
        lst2.append(i)
    cur1 = lst1.head
    for _ in range(5):
        cur1 = cur1.nxt
    cur2 = lst2.head
    while cur2.nxt is not None:
        cur2 = cur2.nxt
    cur2.nxt = cur1
    return (lst1, lst2)


def run(f: Callable[[LinkedList, LinkedList], Node], fn: str):
    print(f"# {fn}")
    lst1, lst2 = make_list()
    print(f"lst1: {lst1}")
    print(f"lst2: {lst2}")
    res = f(lst1, lst2)
    print(f"intersection: {res.data}")
    print()


run(get_intersection1, "get_intersection1")

# # get_intersection1
# lst1: [10, 11, 12, 13, 14, 15, 16, 17, 18, 19]
# lst2: [20, 21, 22, 15, 16, 17, 18, 19]
# intersection: 15
