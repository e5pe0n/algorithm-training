from collections import deque
N = int(input())
G = [[] for _ in range(N)]
for _ in range(N - 1):
    a, b = map(lambda x: int(x) - 1, input().split())
    G[a].append(b)
    G[b].append(a)
C = sorted(list(map(int, input().split())))

res = [0] * N


def bfs():
    global res
    q = deque([0])
    i = N - 1
    res[0] = C[i]
    i -= 1
    while len(q):
        u = q.popleft()
        for v in G[u]:
            if not res[v]:
                res[v] = C[i]
                i -= 1
                q.append(v)


bfs()
score = sum(C) - C[-1]
print(score)
print(' '.join(list(map(str, res))))
