from collections import deque
N, Q = map(int, input().split())
G = [[] for _ in range(N)]
res = [0] * N
passed = [False] * N

for _ in range(N - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)

for _ in range(Q):
    p, x = map(int, input().split())
    res[p - 1] += x


def bfs():
    q = deque([(0, res[0])])
    passed[0] = True
    while len(q) > 0:
        i, d = q.popleft()
        for ni in G[i]:
            if not passed[ni]:
                passed[ni] = True
                res[ni] += d
                q.append((ni, res[ni]))


bfs()
print("\n".join(list(map(str, res))))
