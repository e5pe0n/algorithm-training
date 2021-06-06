from collections import deque


N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    A, B = map(lambda x: int(x) - 1, input().split())
    G[A].append(B)


def bfs(s):
    used = [False] * N
    used[s] = True
    q = deque([s])
    while q:
        u = q.popleft()
        for v in G[u]:
            if not used[v]:
                used[v] = True
                q.append(v)
    return used


res = 0
for u in range(N):
    used = bfs(u)
    for v in range(N):
        if used[v]:
            res += 1
print(res)
