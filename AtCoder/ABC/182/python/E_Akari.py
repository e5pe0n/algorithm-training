H, W, N, M = map(int, input().split())

field = [[0] * W for _ in range(H)]
for _ in range(N):
    a, b = map(int, input().split())
    field[a - 1][b - 1] = 1

for _ in range(M):
    c, d = map(int, input().split())
    field[c - 1][d - 1] = -1


res = 0
for i in range(H):
    j = 0
    while j < W:
        while j < W and field[i][j] != 1:
            j += 1
        while j < W and field[i][j] == 1:
            j += 1
        while j < W and (field[i][j] == 0 or field[i][j] == 2):
            if field[i][j] == 0:
                res += 1
                field[i][j] = 2
            j += 1
    j = W - 1
    while j >= 0:
        while j >= 0 and field[i][j] != 1:
            j -= 1
        while j >= 0 and field[i][j] == 1:
            j -= 1
        while j >= 0 and (field[i][j] == 0 or field[i][j] == 2):
            if field[i][j] == 0:
                res += 1
                field[i][j] = 2
            j -= 1

for j in range(W):
    i = 0
    while i < H:
        while i < H and field[i][j] != 1:
            i += 1
        while i < H and field[i][j] == 1:
            i += 1
        while i < H and (field[i][j] == 0 or field[i][j] == 2):
            if field[i][j] == 0:
                res += 1
                field[i][j] = 2
            i += 1
    i = H - 1
    while i >= 0:
        while i >= 0 and field[i][j] != 1:
            i -= 1
        while i >= 0 and field[i][j] == 1:
            i -= 1
        while i >= 0 and (field[i][j] == 0 or field[i][j] == 2):
            if field[i][j] == 0:
                res += 1
                field[i][j] = 2
            i -= 1
print(res + N)
