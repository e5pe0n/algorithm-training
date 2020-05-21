import heapq


class Vertex:
    def __init__(self, n, distance):
        self.n = n
        self.distance = distance

    def __lt__(self, other):
        return self.distance < other.distance

    def __le__(self, other):
        return self.distance <= other.distance

    def __gt__(self, other):
        return self.distance >= other.distance

    def __ge__(self, other):
        return self.distance > other.distance

    def __str__(self):
        return f'({self.n}, {self.distance})'


q = []
heapq.heapify(q)
heapq.heappush(q, Vertex(0, 100))
heapq.heappush(q, Vertex(1, 100))
heapq.heappush(q, Vertex(2, 5))

print(heapq.heappop(q))
