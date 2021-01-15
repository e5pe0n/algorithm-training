from collections import deque


class Edge:
    def __init__(self, u, v, idx):
        self.u = u
        self.v = v
        self.idx = idx


N = int(input())
AB = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(N - 1)]
G = [[] for _ in range(N)]
for i, (a, b) in enumerate(AB):
    G[a].append(Edge(a, b, i))
    G[b].append(Edge(b, a, i))
K = max(list(map(len, G)))
res = [-1] * (N - 1)


def bfs():
    global res
    q = deque([(0, K)])
    while len(q):
        u, c = q.popleft()
        cnt = 0
        for e in G[u]:
            if res[e.idx] < 0:
                res[e.idx] = cnt + int(cnt >= c)
                cnt += 1
                q.append((e.v, res[e.idx]))


bfs()
print(K)
print('\n'.join(list(map(lambda x: str(x + 1), res))))
