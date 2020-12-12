H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]


for i in range(H):
    for j in range(W):
        if S[i][j] == '#':
            continue
        cnt = 0
        for di in range(-1, 2):
            for dj in range(-1, 2):
                i2 = i + di
                j2 = j + dj
                if 0 <= i2 < H and 0 <= j2 < W and S[i2][j2] == '#':
                    cnt += 1
        S[i][j] = str(cnt)
print('\n'.join(list(map(''.join, S))))
