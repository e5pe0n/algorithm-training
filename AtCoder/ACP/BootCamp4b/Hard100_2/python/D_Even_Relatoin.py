from collections import deque


class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


N = int(input())
UVW = [list(map(int, input().split())) for _ in range(N - 1)]
G = [[] for _ in range(N)]
for u, v, w in UVW:
    G[u - 1].append(Edge(u - 1, v - 1, w))
    G[v - 1].append(Edge(v - 1, u - 1, w))

res = [0] + [-1] * (N - 1)


def bfs():
    global res
    q = deque([0])
    while len(q):
        u = q.popleft()
        for e in G[u]:
            if res[e.v] < 0:
                res[e.v] = (res[e.u] + e.w) % 2
                q.append(e.v)


bfs()
print('\n'.join(list(map(str, res))))
