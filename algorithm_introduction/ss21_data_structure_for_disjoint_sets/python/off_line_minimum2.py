from typing import List

n = 9
m = 5
extracted = [0] * m


class El:
    def __init__(self, n):
        self.n = n
        self.p = self
        self.rank = 0


def find(x: El) -> El:
    if x.p == x:
        return x
    else:
        x.p = find(x.p)
        return x.p


def union(x: El, y: El):
    x = find(x)
    y = find(y)
    if (x is y):
        return

    if x.rank > y.rank:
        y.p = x
    else:
        x.p = y
        if x.rank == y.rank:
            y.rank += 1


def same(x: El, y: El) -> bool:
    return find(x) is find(y)


def off_line_minimum(m, n, els: List[El], K: List[El]):
    for i in range(n + 1):
        for j in range(m):
            if K[j] is None:
                continue
            if same(els[i], K[j]):
                extracted[j] = i
                r = j + 1
                while K[r] is None:
                    r += 1
                union(K[j], K[r])
                K[j] = None
                break


# K = [[8, 2], [4, 5], [], [3, 6, 9], [1, 0], [7]]
# n=10 is used to represent empty set and None is for broken set.

els = [El(i) for i in range(11)]

union(els[8], els[2])
union(els[4], els[5])
union(els[3], els[6])
union(els[6], els[9])
union(els[1], els[0])

K = [els[8], els[4], els[10], els[3], els[1], els[7]]

off_line_minimum(m, n, els, K)

print(extracted)    # [2, 4, 5, 3, 0]
