from collections import deque
INF = float('inf')
N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)
K = int(input())
C = list(map(lambda x: int(x) - 1, input().split()))


dist = [[INF] * K for _ in range(K)]


def bfs(s):
    global dist
    d = [INF] * N
    d[C[s]] = 0
    q = deque([C[s]])
    while len(q):
        u = q.popleft()
        for v in G[u]:
            if d[v] > d[u] + 1:
                d[v] = d[u] + 1
                q.append(v)
    for i in range(K):
        dist[s][i] = d[C[i]]


for i in range(K):
    bfs(i)

dp = [[INF] * K for _ in range(1 << K)]
for k in range(K):
    dp[1 << k][k] = 1

for S in range(1, 1 << K):
    for u in range(K):
        if not (S & (1 << u)):
            continue
        for v in range(K):
            if S & (1 << v):
                continue
            dp[S | (1 << v)][v] = min(dp[S | (1 << v)][v], dp[S][u] + dist[u][v])

res = min(dp[(1 << K) - 1])
if res == INF:
    res = -1
print(res)
