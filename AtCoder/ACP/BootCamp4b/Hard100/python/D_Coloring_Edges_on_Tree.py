from collections import deque


class Edge:
    def __init__(self, idx, u, v):
        self.idx = idx
        self.u = u
        self.v = v


N = int(input())
E = [[] for _ in range(N)]
used = [False] * N
C = [0] * (N - 1)
for i in range(N - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    E[a].append(Edge(i, a, b))
    E[b].append(Edge(i, b, a))

K = max(map(len, E))

q = deque([[0, -1, -1]])
while len(q) > 0:
    u, idx, c = q.popleft()
    if used[u]:
        continue
    used[u] = True
    if idx >= 0 and c >= 0:
        C[idx] = c
    i = 1
    for e in E[u]:
        if not used[e.v]:
            q.append([e.v, e.idx, (c + i) % K])
            i += 1

print(K)
for c in C:
    print(c + 1)
