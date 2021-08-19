from collections import deque
INF = float('inf')


N = int(input())
G = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)


def bfs():
    q = deque([0])
    dist = [INF] * N
    dist[0] = 0
    odd, even = [], []
    even.append(0)
    while q:
        u = q.popleft()
        for v in G[u]:
            if dist[v] > dist[u] + 1:
                dist[v] = dist[u] + 1
                if dist[v] % 2 == 0:
                    even.append(v)
                else:
                    odd.append(v)
                q.append(v)
    return (odd, even)


odd, even = bfs()
res = odd if len(odd) >= N // 2 else even
print(' '.join(map(lambda x: str(x + 1), res[:N // 2])))
