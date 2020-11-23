R, C, K = map(int, input().split())
V = [[0] * (C + 1) for _ in range(R + 1)]
for _ in range(K):
    r, c, v = map(int, input().split())
    V[r][c] = v


prv = [[0] * 4 for _ in range(C + 1)]
nxt = [[0] * 4 for _ in range(C + 1)]

for i in range(1, R + 1):
    for j in range(1, C + 1):
        for k in range(4):
            nxt[j][0] = max(nxt[j][0], prv[j][k])
            nxt[j][k] = max(nxt[j][k], nxt[j - 1][k])
        for k in range(2, -1, -1):
            nxt[j][k + 1] = max(nxt[j][k + 1], nxt[j][k] + V[i][j])
    prv, nxt = nxt, prv
print(max(prv[C]))
