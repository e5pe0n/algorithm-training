H, W = map(int, input().split())
S = [list(input()) for _ in range(H)]
T = [["."] * W for _ in range(H)]
for i in range(H):
    for j in range(W):
        if S[i][j] == '.':
            continue
        white = 0
        for di in range(-1, 2):
            for dj in range(-1, 2):
                _i = i + di
                _j = j + dj
                if 0 <= _i < H and 0 <= _j < W and S[_i][_j] == '.':
                    white += 1
        if white == 0:
            T[i][j] = '#'
for i in range(H):
    for j in range(W):
        black = 0
        for di in range(-1, 2):
            for dj in range(-1, 2):
                _i = i + di
                _j = j + dj
                if 0 <= _i < H and 0 <= _j < W and T[_i][_j] == '#':
                    black += 1
        if (S[i][j] == '#' and black == 0) or (S[i][j] == '.' and black > 0):
            print("impossible")
            exit()
print("possible")
print('\n'.join(''.join(t) for t in T))
