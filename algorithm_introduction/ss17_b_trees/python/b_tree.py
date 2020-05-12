from typing import Tuple


class Node:
    def __init__(self):
        self.n = 0
        self.leaf = False
        self.key = []
        self.c = []


def disk_read(x: Node):
    pass


def disk_write(x: Node):
    pass


class Tree:
    def __init__(self):
        self.root = None
        self.t = 2

    def allocate_node(self):
        x = Node()
        return x

    def b_tree_create(self):
        x = self.allocate_node()
        x.leaf = True
        x.n = 0
        disk_write(x)
        self.root = x

    def b_tree_search(self, x: Node, k: int) -> Tuple[Node, int]:
        i = 0
        while i < x.n and k > x.key[i]:
            i += 1
        if i <= x.n and k == x.key[i]:
            return (x, i)
        elif x.leaf:
            return (None, -1)
        else:
            disk_read(x.c[i])
            return self.b_tree_search(x.c[i], k)

    def b_tree_split_child(self, x: Node, i: int):
        z = self.allocate_node()
        y = x.c[i]
        z.leaf = y.leaf
        z.n = self.t - 1
        for j in range(self.t - 1):
            z.key[j] = y.key[j + self.t]
        if not y.leaf:
            for j in range(self.t):
                z.c[j] = y.c[j + self.t]
        y.n = self.t - 1
        for j in range(x.n, i, -1):
            x.c[j + 1] = x.c[j]
        x.c[i + 1] = z
        for j in range(x.n - 1, i - 1, -1):
            x.key[j + 1] = x.key[j]
        x.key[i] = y.key[self.t]
        x.n += 1
        disk_write(y)
        disk_write(z)
        disk_write(x)

    def b_tree_insert_nonfull(self, x: Node, k: int):
        i = x.n - 1
        if x.leaf:
            while i >= 0 and k < x.key[i]:
                x.key[i + 1] = x.key[i]
                i -= 1
            x.key[i + 1] = k
            x.n += 1
            disk_write(x)
        else:
            while i >= 0 and k < x.key[i]:
                i -= 1
            i += 1
            disk_read(x.c[i])
            if x.c[i].n == 2 * self.t - 1:
                self.b_tree_split_child(x, i)
                if k > x.key[i]:
                    i += 1
                self.b_tree_insert_nonfull(x.c[i], k)

    def b_tree_insert(self, k: int):
        r = self.root
        if r.n == 2 * self.t - 1:
            s = self.allocate_node()
            self.root = s
            s.leaf = False
            s.n = 0
            s.c[0] = r
            self.b_tree_split_child(s, 0)
            self.b_tree_insert_nonfull(s, k)
        else:
            self.b_tree_insert_nonfull(r, k)

    def b_tree_delete(self, x: Node, k: int):
        idx = 0
        while idx < x.n and k > x.key[idx]:
            idx += 1
        if idx < x.n and k == x.key[idx]:
            if x.leaf:
                for i in range(idx, x.n):
                    x.key[i] = x.key[i + 1]
                return
            else:
                if idx == x.n:
                    idx -= 1
                y = x.c[idx]
                z = x.c[idx + 1]
                if y.n >= self.t:
                    _k = y.key[y.n - 1]
                    x.key[idx] = _k
                    self.b_tree_delete(y, _k)
                elif z.n >= self.t:
                    _k = z.key[z.n - 1]
                    x.key[idx] = _k
                    self.b_tree_delete(z, _k)
                else:
                    y.key[y.n] = x.key[idx]
                    for i in range(z.n):
                        y.key[y.n + 1 + i] = z.key[i]
                        y.c[y.n + 1 + i] = z.c[i]
                    y.c[y.n + 1 + z.n] = z.c[z.n]
                    y.n += 1 + z.n
                    for i in range(idx, x.n - 1):
                        x.key[i] = x.key[i + 1]
                    for i in range(idx + 1, x.n):
                        x.c[i] = x[i + 1]
                    self.b_tree_delete(y, k)
        else:
            if x.c[idx].n <= self.t - 1:
                if idx > 0 and x.c[idx - 1].n >= self.t:
                    for j in range(x.c[idx].n - 1, 0, -1):
                        x.c[idx].key[j + 1] = x.c[idx].key[j]
                    x.c[idx].key[0] = x.key[idx]
                    x.key[idx] = x.c[idx - 1].key[x.c[idx - 1].n - 1]
                    for j in range(x.c[idx].n, 0, -1):
                        x.c[idx].c[j + 1] = x.c[idx].c[j]
                    x.c[idx].c[0] = x.c[idx - 1].c[x.c[idx - 1].n]
                    x.c[idx - 1].n -= 1
                    x.c[idx].n += 1
                    self.b_tree_delete(x.c[idx], k)
                elif idx < x.n and x.c[idx + 1].n >= self.t:
                    x.c[idx].key[x.c[idx].n] = x.key[idx]
                    x.key[idx] = x.c[idx + 1].key[0]
                    for j in range(1, x.c[idx + 1].n):
                        x.c[idx + 1].key[j - 1] = x.c[idx + 1].key[j]
                    x.c[idx].c[x.c[idx].n + 1] = x.c[idx + 1].c[0]
                    for j in range(x.c[idx + 1].n, 0):
                        x.c[idx + 1].c[j - 1] = x.c[idx + 1].c[j]
                    x.c[idx + 1].n -= 1
                    x.c[idx].n -= 1
                    self.b_tree_delete(x.c[idx], k)
                else:
                    if idx > 0:
                        x.c[idx - 1].key[x.c[idx - 1].n] = x.key[idx - 1]
                        for j in range(x.c[idx].n):
                            x.c[idx - 1].key[x.c[idx - 1].n + 1 + j] = x.c[idx].key[j]
                            x.c[idx - 1].c[x.c[idx - 1].n + 1 + j] = x.c[idx].c[j]
                        x.c[idx - 1].c[x.c[idx - 1].n + 1 + x.c[idx].n] = x.c[idx].c[x.c[idx].n]
                        x.c[idx - 1].n += 1 + x.c[idx].n
                        for j in range(idx - 1, x.n - 1):
                            x.key[j] = x.key[j + 1]
                            x.c[j] = x.c[j + 1]
                        x.c[x.n - 1] = x.c[x.n]
                        x.n -= 1
                        self.b_tree_delete(x.c[idx - 1], k)
                    else:
                        x.c[idx].key[x.c[idx].n] = x.key[idx]
                        for j in range(x.c[idx + 1].n):
                            x.c[idx].key[x.c[idx].n + 1 + j] = x.c[idx + 1].key[j]
                            x.c[idx].c[x.c[idx].n + 1 + j] = x.c[idx + 1].c[j]
                        x.c[idx].c[x.c[idx].n + 1 + x.c[idx + 1].n] = x.c[idx + 1].c[x.c[idx + 1].n]
                        x.c[idx].n += 1 + x.c[idx + 1].n
                        for j in range(idx, x.n - 1):
                            x.key[j] = x.key[j + 1]
                            x.c[j] = x.c[j + 1]
                        x.c[x.n - 1] = x.c[x.n]
                        x.n -= 1
                        self.b_tree_delete(x.c[idx], k)
