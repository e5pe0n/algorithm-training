INF = 1_000_000_000


H, W = [int(x) for x in input().split()]
S = [input() for _ in range(H)]
D = [[INF] * W for _ in range(H)]
black = sum([len([_s for _s in s if _s == '#']) for s in S])


def at(i, j):
    if 0 <= i < H and 0 <= j < W and S[i][j] == '.':
        return D[i][j]
    else:
        return INF


D[0][0] = 1
for _ in range(H * W):
    for i in range(H):
        for j in range(W):
            if S[i][j] == '.':
                top = at(i - 1, j)
                low = at(i + 1, j)
                left = at(i, j - 1)
                right = at(i, j + 1)
                D[i][j] = min(D[i][j], top + 1, low + 1, left + 1, right + 1)
ans = -1
if D[H - 1][W - 1] < INF:
    ans = H * W - black - D[H - 1][W - 1]
print(ans)
