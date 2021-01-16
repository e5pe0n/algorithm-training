H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]

res = []
for i in range(H):
    if i % 2 == 0:
        for j in range(W):
            if A[i][j] % 2 == 0:
                continue
            if j + 1 < W:
                A[i][j + 1] += 1
                A[i][j] -= 1
                res.append((i, j, i, j + 1))
            elif i + 1 < H:
                A[i + 1][j] += 1
                A[i][j] -= 1
                res.append((i, j, i + 1, j))
    else:
        for j in range(W - 1, -1, -1):
            if A[i][j] % 2 == 0:
                continue
            if j - 1 >= 0:
                A[i][j - 1] += 1
                A[i][j] -= 1
                res.append((i, j, i, j - 1))
            elif i + 1 < H:
                A[i + 1][j] += 1
                A[i][j] -= 1
                res.append((i, j, i + 1, j))
print(len(res))
print('\n'.join([' '.join(list(map(lambda x: str(x + 1), r))) for r in res]))
