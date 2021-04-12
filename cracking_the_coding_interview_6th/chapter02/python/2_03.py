# https://www.geeksforgeeks.org/data-structures/linked-list/
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

    def get_ptr(self, key):
        cur = self.head
        while cur is not None:
            if cur.data == key:
                return cur
            cur = cur.nxt
        return cur


def del_md_node1(md: Node):
    if md is None or md.nxt is None:
        return False
    md.data = md.nxt.data
    md.nxt = md.nxt.nxt
    return True


def make_list(s):
    lst = LinkedList()
    for c in s:
        lst.append(ord(c))
    return lst


def run(f, fn, ps):
    print(f"# {fn}")
    for k, s in ps:
        k = ord(k)
        lst = make_list(s)
        before = repr(lst)
        f(lst.get_ptr(k))
        after = repr(lst)
        print(f"{k}: {before} -> {after}")
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/2_03.txt") as f:
    n = int(ns(f))
    ps = [ns(f).split() for _ in range(n)]

run(del_md_node1, "del_md_node1", ps)
