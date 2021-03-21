from heapq import heapify, heappop, heappush
N = int(input())
G = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

used = [False] * N
q = [0]
heapify(q)
res = []
while len(q):
    u = heappop(q)
    if used[u]:
        continue
    used[u] = True
    res.append(u)
    for v in G[u]:
        if not used[v]:
            heappush(q, v)
print(' '.join(list(map(lambda x: str(x + 1), res))))
