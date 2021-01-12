H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
C = [[0] * W for _ in range(H)]

for i in range(H):
    left = 0
    right = 0
    while right < W:
        while right < W and S[i][right] == '#':
            right += 1
        left = right
        while right < W and S[i][right] == '.':
            right += 1
        cnt = right - left
        while left < right:
            C[i][left] = cnt
            left += 1
for j in range(W):
    top = 0
    bottom = 0
    while bottom < H:
        while bottom < H and S[bottom][j] == '#':
            bottom += 1
        top = bottom
        while bottom < H and S[bottom][j] == '.':
            bottom += 1
        cnt = bottom - top
        while top < bottom:
            C[top][j] += cnt
            top += 1
res = 0
for i in range(H):
    for c in C[i]:
        res = max(res, c - 1)
print(res)
