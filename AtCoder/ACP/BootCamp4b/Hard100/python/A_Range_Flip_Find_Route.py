H, W = [int(x) for x in input().split()]
S = [input() for _ in range(H)]
C = [[0] * W for _ in range(H)]

for i in range(H):
    for j in range(W):
        if i - 1 >= 0 and j - 1 >= 0:
            C[i][j] = min(C[i - 1][j] + int(S[i - 1][j] == '.' and S[i][j] == '#'),
                          C[i][j - 1] + int(S[i][j - 1] == '.' and S[i][j] == '#'))
        elif i - 1 >= 0:
            C[i][j] = C[i - 1][j] + int(S[i - 1][j] == '.' and S[i][j] == '#')
        elif j - 1 >= 0:
            C[i][j] = C[i][j - 1] + int(S[i][j - 1] == '.' and S[i][j] == '#')
        else:
            C[i][j] = int(S[i][j] == '#')

print(C[H - 1][W - 1])
