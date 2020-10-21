from collections import deque


class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


N = int(input())
E = [[] for _ in range(N)]
D = [0] * N
used = [False] * N
for _ in range(N - 1):
    a, b, c = map(int, input().split())
    a -= 1
    b -= 1
    E[a].append(Edge(a, b, c))
    E[b].append(Edge(b, a, c))
Q, K = map(int, input().split())
X = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(Q)]

q = deque([K - 1])
while len(q) > 0:
    u = q.popleft()
    used[u] = True
    for e in E[u]:
        if not used[e.v]:
            D[e.v] = D[u] + e.w
            q.append(e.v)
for x in X:
    print(D[x[0]] + D[x[1]])
