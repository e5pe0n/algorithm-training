from heapq import heapify, heappop, heappush


class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

    def __lt__(self, other):
        return self.w > other.w

    def __gt__(self, other):
        return self.w < other.w


q = []
heapify(q)
heappush(q, Edge(1, 2, 1))
heappush(q, Edge(0, 1, 5))
heappush(q, Edge(0, 2, 3))
while len(q):
    e = heappop(q)
    print(e.w)    # 5 3 1
