import sys
H, W = list(map(int, input().split()))
C = [list(input()) for _ in range(H)]
for i in range(H):
    for j in range(W):
        if C[i][j] == '#':
            cnt = 0
            if i - 1 >= 0 and C[i - 1][j] == '#':
                cnt += 1
            if i + 1 < H and C[i + 1][j] == '#':
                cnt += 1
            if j - 1 >= 0 and C[i][j - 1] == '#':
                cnt += 1
            if j + 1 < W and C[i][j + 1] == '#':
                cnt += 1
            if cnt == 0:
                print('No')
                sys.exit()
print('Yes')
