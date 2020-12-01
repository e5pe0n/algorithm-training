from collections import deque


N, M = map(int, input().split())
X = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
G = [[] for _ in range(N)]
for a, b in X:
    G[a].append(b)
    G[b].append(a)


def bfs():
    path = [0] + [-1] * (N - 1)
    q = deque([0])
    while len(q) > 0:
        u = q.popleft()
        for v in G[u]:
            if path[v] < 0:
                path[v] = u
                q.append(v)
    return path


path = bfs()
if -1 in path:
    print("No")
    exit()
print("Yes")
for p in path[1:]:
    print(p + 1)
