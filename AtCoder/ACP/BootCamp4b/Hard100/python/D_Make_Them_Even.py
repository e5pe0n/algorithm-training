H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
V = []
c = 0
for i in range(H):
    if i % 2 == 0:
        for j in range(W):
            c += 1
            if A[i][j] % 2 == 0 or c == H * W:
                continue
            if j < W - 1:
                A[i][j + 1] += 1
                V.append([i, j, i, j + 1])
            else:
                A[i + 1][j] += 1
                V.append([i, j, i + 1, j])
    else:
        for j in range(W - 1, -1, -1):
            c += 1
            if A[i][j] % 2 == 0 or c == H * W:
                continue
            if j > 0:
                A[i][j - 1] += 1
                V.append([i, j, i, j - 1])
            else:
                A[i + 1][j] += 1
                V.append([i, j, i + 1, j])
print(len(V))
for v in V:
    print(" ".join(map(lambda x: str(x + 1), v)))
