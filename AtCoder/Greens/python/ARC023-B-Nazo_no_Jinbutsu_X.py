R, C, D = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(R)]

res = 0
for i in range(min(D + 1, R)):
    for j in range(min(D - i + 1, C)):
        if ((i + j) % 2 == (D % 2)):
            res = max(res, A[i][j])
print(res)
