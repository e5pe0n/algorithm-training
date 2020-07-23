import sys
H, W = list(map(int, input().split()))
A = [input() for _ in range(H)]
for i in range(H - 1):
    for j in range(W - 1):
        if A[i + 1][j] == '#' and A[i][j + 1] == '#':
            print('Impossible')
            sys.exit()
print('Possible')
