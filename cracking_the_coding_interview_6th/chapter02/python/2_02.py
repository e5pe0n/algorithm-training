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

    def last_kth1(self, k):
        length = len(self)
        assert k < length
        cur = self.head
        cnt = length - k - 1
        while cnt:
            cur = cur.nxt
            cnt -= 1
        return cur.data

    def _last_kth2(self, node, cnt):
        if cnt == 0:
            return node.data
        return self._last_kth2(node.nxt, cnt - 1)

    def last_kth2(self, k):
        length = len(self)
        assert k < length
        return self._last_kth2(self.head, length - k - 1)

    def _last_kth3(self, node, k, i):
        if node is None:
            return -1
        res = self._last_kth3(node.nxt, k, i)
        i[0] += 1
        if i[0] - 1 == k:
            return node.data
        return res

    def last_kth3(self, k):
        i = [0]
        return self._last_kth3(self.head, k, i)


def make_list(s):
    lst = LinkedList()
    for c in s:
        lst.append(int(c))
    return lst


def show(fn, v):
    print(f"# {fn}")
    for k, s in v:
        lst = make_list(s)
        print(f"the last {k} th of {lst}: {getattr(lst, fn)(k)}")
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/2_02.txt") as f:
    n = int(ns(f))

    def parse(line):
        k, s = line.split()
        return (int(k), s)
    v = [parse(ns(f)) for _ in range(n)]

show("last_kth1", v)
show("last_kth2", v)
show("last_kth3", v)
