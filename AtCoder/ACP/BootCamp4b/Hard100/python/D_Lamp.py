H, W = [int(x) for x in input().split()]
S = [input() for _ in range(H)]
C = [[0] * W for _ in range(H)]

for i in range(H):
    left = 0
    right = 0
    while right < W:
        while right < W and S[i][right] == '.':
            right += 1
        for j in range(left, right):
            C[i][j] = right - left
        while right < W and S[i][right] == '#':
            right += 1
        left = right
for j in range(W):
    top = 0
    bottom = 0
    while bottom < H:
        while bottom < H and S[bottom][j] == '.':
            bottom += 1
        for i in range(top, bottom):
            C[i][j] += bottom - top
        while bottom < H and S[bottom][j] == '#':
            bottom += 1
        top = bottom

ans = max([max(c) for c in C])
print(max(0, ans - 1))
