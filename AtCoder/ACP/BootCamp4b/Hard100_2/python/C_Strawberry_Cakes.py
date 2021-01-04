H, W, K = map(int, input().split())
S = [list(input()) for _ in range(H)]
res = [[0] * W for _ in range(H)]
V = []
for i in range(H):
    for j in range(W):
        if S[i][j] == '#':
            V.append(i)
            break
prv_i = 0
for v in V:
    V2 = []
    for j in range(W):
        for i in range(prv_i, v + 1):
            if S[i][j] == '#':
                V2.append(j)
                break
    prv_j = 0
    for v2 in V2:
        for j in range(prv_j, v2 + 1):
            for i in range(prv_i, v + 1):
                res[i][j] = K
        K -= 1
        prv_j = v2 + 1
    for j in range(V2[-1] + 1, W):
        for i in range(prv_i, v + 1):
            res[i][j] = res[i][V2[-1]]
    prv_i = v + 1
for i in range(V[-1] + 1, H):
    for j in range(W):
        res[i][j] = res[V[-1]][j]
print('\n'.join([' '.join(list(map(str, s))) for s in res]))
