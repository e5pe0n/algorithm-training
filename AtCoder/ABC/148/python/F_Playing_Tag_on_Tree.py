from collections import deque
INF = float('inf')
N, u, v = map(int, input().split())
u -= 1
v -= 1
G = [[] for _ in range(N)]
for _ in range(N - 1):
    A, B = map(lambda x: int(x) - 1, input().split())
    G[A].append(B)
    G[B].append(A)


def bfs(s):
    d = [INF] * N
    d[s] = 0
    q = deque([s])
    while len(q):
        u = q.popleft()
        for v in G[u]:
            if d[v] > d[u] + 1:
                d[v] = d[u] + 1
                q.append(v)
    return d


d1 = bfs(u)
d2 = bfs(v)
res = max(x2 for x1, x2 in zip(d1, d2) if x1 < x2) - 1
lst = [x2 for x1, x2 in zip(d1, d2) if x1 == x2]
if len(lst) and min(lst) > res:
    res = min(lst)
print(res)
