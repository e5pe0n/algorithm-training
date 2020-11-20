H, W = [int(i) for i in input().split()]
S = [[s for s in input()] for _ in range(H)]

for i in range(H):
    for j in range(W):
        if S[i][j] == '.':
            cnt = 0
            for _i in range(max(0, i - 1), min(H, i + 2)):
                for _j in range(max(0, j - 1), min(W, j + 2)):
                    if S[_i][_j] == '#':
                        cnt += 1
            S[i][j] = str(cnt)
print('\n'.join([''.join(s) for s in S]))
