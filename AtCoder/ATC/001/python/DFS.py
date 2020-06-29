H, W = [int(i) for i in input().split()]
C = [[c for c in input()] for _ in range(H)]
B = [[False] * W for _ in range(H)]

for i in range(H):
    for j in range(W):
        if C[i][j] == 's':
            si = i
            sj = j
            break


def f(i, j):
    return 0 <= i < H and 0 <= j < W and not B[i][j]


def dfs(i, j):
    B[i][j] = True
    for _i, _j in ((i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)):
        if f(_i, _j):
            if C[_i][_j] == 'g':
                return True
            elif C[_i][_j] == '.':
                if dfs(_i, _j):
                    return True
    return False


if dfs(si, sj):
    print('Yes')
else:
    print('No')
