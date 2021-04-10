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
            lst.append(str(node.data))
            node = node.nxt
        return " ".join(lst)

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

    def drop_dup1(self):
        # time O(n^2), space O(1)
        src = self.head
        if src is None or src.nxt is None:
            return

        while src is not None:
            prv = src
            seeker = src.nxt
            while seeker is not None:
                if seeker.data == src.data:
                    prv.nxt = seeker.nxt
                    seeker = prv.nxt
                else:
                    prv = seeker
                    seeker = seeker.nxt
            src = src.nxt

    def drop_dup2(self):
        # time O(n), space O(n)
        prv = None
        cur = self.head
        st = set()
        while cur is not None:
            if cur.data in st:
                prv.nxt = cur.nxt
                cur = cur.nxt
            else:
                st.add(cur.data)
                prv = cur
                cur = cur.nxt


def make_list(s):
    lst = LinkedList()
    for c in s:
        lst.append(ord(c))
    return lst


def show(f, fn, vs):
    print(f"# {fn}")
    for s in vs:
        lst = make_list(s)
        before = repr(lst)
        f(lst)
        after = repr(lst)
        print(f"{before} -> {after}")
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/2_01.txt") as f:
    n = int(ns(f))
    vs = [ns(f) for _ in range(n)]

show(lambda x: x.drop_dup1(), "drop_dup1", vs)
show(lambda x: x.drop_dup2(), "drop_dup2", vs)

# # drop_dup1
# 70 79 76 76 79 87 85 80 -> 70 79 76 87 85 80
# 84 69 83 84 67 65 83 69 83 -> 84 69 83 67 65
# 65 65 65 65 65 -> 65

# # drop_dup2
# 70 79 76 76 79 87 85 80 -> 70 79 76 87 85 80
# 84 69 83 84 67 65 83 69 83 -> 84 69 83 67 65
# 65 65 65 65 65 -> 65
