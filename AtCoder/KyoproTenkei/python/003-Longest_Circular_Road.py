from collections import deque
INF = float("inf")
N = int(input())
G = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)


def bfs(s):
    dist = [INF] * N
    dist[s] = 0
    q = deque([s])
    while q:
        u = q.popleft()
        for v in G[u]:
            if dist[v] > dist[u] + 1:
                dist[v] = dist[u] + 1
                q.append(v)
    return dist


dist1 = bfs(0)
max_d = 0
s = 0
for i, d in enumerate(dist1):
    if max_d < d:
        max_d = d
        s = i
dist2 = bfs(s)
print(max(dist2) + 1)
