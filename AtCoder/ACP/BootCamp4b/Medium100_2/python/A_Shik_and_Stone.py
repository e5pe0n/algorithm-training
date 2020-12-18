H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]
i, j = 0, 0
A[i][j] = '.'
while i != H - 1 or j != W - 1:
    f = False
    while j + 1 < W and A[i][j + 1] == '#':
        j += 1
        A[i][j] = '.'
        f = True
    if i + 1 < H and A[i + 1][j] == '#':
        i += 1
        A[i][j] = '.'
        f = True
    if not f:
        print("Impossible")
        exit()
if any(list(map(lambda x: '#' in x, A))):
    print("Impossible")
else:
    print("Possible")
