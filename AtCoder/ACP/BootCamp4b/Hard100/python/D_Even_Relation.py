from collections import deque


class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


N = int(input())
E = [[] for _ in range(N)]
used = [False] * N
C = [False] * N
for _ in range(N - 1):
    u, v, w = map(int, input().split())
    E[u - 1].append(Edge(u - 1, v - 1, w))
    E[v - 1].append(Edge(v - 1, u - 1, w))

q = deque([0])
while len(q) > 0:
    p = q.popleft()
    if used[p]:
        continue
    used[p] = True
    for e in E[p]:
        if not used[e.v]:
            if e.w % 2 == 0:
                C[e.v] = C[p]
            else:
                C[e.v] = not C[p]
            q.append(e.v)
for c in C:
    print(int(c))
