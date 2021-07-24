from collections import deque
INF = float("inf")
MOD = 10**9 + 7
N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)

D = [INF] * N
D[0] = 0
C = [0] * N
C[0] = 1


def bfs():
    global D, C
    q = deque([0])
    while q:
        u = q.popleft()
        for v in G[u]:
            if D[v] == D[u] + 1:
                C[v] = (C[v] + C[u]) % MOD
            elif D[v] > D[u] + 1:
                C[v] = C[u]
                D[v] = D[u] + 1
                q.append(v)


bfs()
print(C[N - 1])
