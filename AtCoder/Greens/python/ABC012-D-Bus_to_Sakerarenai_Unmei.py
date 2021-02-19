INF = float('inf')
N, M = map(int, input().split())
d = [[0 if i == j else INF for j in range(N)] for i in range(N)]
for _ in range(M):
    a, b, t = map(int, input().split())
    a -= 1
    b -= 1
    d[a][b] = t
    d[b][a] = t


def warshall_floyd():
    global d
    for k in range(N):
        for i in range(N):
            for j in range(N):
                d[i][j] = min(d[i][j], d[i][k] + d[k][j])


warshall_floyd()
res = INF
for i in range(N):
    worst = 0
    for j in range(N):
        worst = max(worst, d[i][j])
    res = min(res, worst)
print(res)
