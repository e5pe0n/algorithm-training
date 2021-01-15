H, W, A, B = map(int, input().split())
if A * 2 > W or B * 2 > H:
    print("No")
    exit()
res = [[None] * W for _ in range(H)]
for i in range(H):
    for j in range(W):
        if j < A and i < B:
            res[i][j] = '1'
        elif j < A and i >= B:
            res[i][j] = '0'
        elif j >= A and i < B:
            res[i][j] = '0'
        else:
            res[i][j] = '1'
print('\n'.join(list(map(''.join, res))))
