H, W = [int(i) for i in input().split()]
A = [[a for a in input()] for _ in range(H)]

i = 0
while i < H:
    j = 0
    while j < W and A[i][j] == '.':
        j += 1
    if j >= W:
        for k in range(i, H - 1):
            for j in range(W):
                A[k][j] = A[k + 1][j]
        H -= 1
    else:
        i += 1
j = 0
while j < W:
    i = 0
    while i < H and A[i][j] == '.':
        i += 1
    if i >= H:
        for k in range(j, W - 1):
            for i in range(H):
                A[i][k] = A[i][k + 1]
        W -= 1
    else:
        j += 1
for i in range(H):
    for j in range(W):
        print(A[i][j], end='')
    print()
