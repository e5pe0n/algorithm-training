N, M = map(int, input().split())
H = list(map(int, input().split()))
C = [list(map(int, input().split())) for _ in range(M)]
G = [[] for _ in range(N)]
for a, b in C:
    a -= 1
    b -= 1
    G[a].append(b)
    G[b].append(a)
res = 0
for u in range(N):
    cnt = 0
    for v in G[u]:
        if H[u] > H[v]:
            cnt += 1
    if cnt == len(G[u]):
        res += 1
print(res)
