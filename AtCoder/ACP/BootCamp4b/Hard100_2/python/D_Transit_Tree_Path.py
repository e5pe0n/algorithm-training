from collections import deque
INF = float('inf')


class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


N = int(input())
ABC = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(N - 1)]
Q, K = map(int, input().split())
K -= 1
XY = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(Q)]
G = [[] for _ in range(N)]
for a, b, c in ABC:
    G[a].append(Edge(a, b, c + 1))
    G[b].append(Edge(b, a, c + 1))
d = [INF] * N
d[K] = 0


def bfs():
    global d
    q = deque([K])
    while len(q):
        u = q.popleft()
        for e in G[u]:
            if d[e.v] > d[u] + e.w:
                d[e.v] = d[u] + e.w
                q.append(e.v)


bfs()
print('\n'.join(list(map(lambda x: str(d[x[0]] + d[x[1]]), XY))))
