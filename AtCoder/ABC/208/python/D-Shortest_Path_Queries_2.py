INF = float("inf")
N, M = map(int, input().split())
d = [[0 if i == j else INF for j in range(N)] for i in range(N)]
for _ in range(M):
    A, B, C = map(int, input().split())
    d[A - 1][B - 1] = C
res = 0
for k in range(N):
    nxt = [[0] * N for _ in range(N)]
    for i in range(N):
        for j in range(N):
            nxt[i][j] = min(d[i][j], d[i][k] + d[k][j])
            if nxt[i][j] < INF:
                res += nxt[i][j]
    d = nxt
print(res)
