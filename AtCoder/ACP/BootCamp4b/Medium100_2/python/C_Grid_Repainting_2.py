di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]


H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
for i in range(H):
    for j in range(W):
        if S[i][j] == '#':
            f = False
            for _di, _dj in zip(di, dj):
                ni = i + _di
                nj = j + _dj
                if 0 <= ni < H and 0 <= nj < W and S[ni][nj] == '#':
                    f = True
                    break
            if not f:
                print("No")
                exit()
print("Yes")
