from sys import setrecursionlimit
setrecursionlimit(10**9)

N, M = map(int, input().split())
G = [[] for _ in range(N)]
H = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    G[a].append(b)
    H[b].append(a)

cnt = 0
used = [False] * N
V = []


def dfs(u):
    global used, V
    used[u] = True
    for v in G[u]:
        if not used[v]:
            dfs(v)
    V.append(u)


def dfs2(u):
    global used, cnt
    used[u] = True
    cnt += 1
    for v in H[u]:
        if not used[v]:
            dfs2(v)


for u in range(N):
    if not used[u]:
        dfs(u)
used = [False] * N
res = 0
for u in V[::-1]:
    if not used[u]:
        cnt = 0
        dfs2(u)
        res += cnt * (cnt - 1) // 2
print(res)
