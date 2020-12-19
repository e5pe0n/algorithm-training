H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]
min_a = min(map(min, A))
res = 0
for i in range(H):
    for j in range(W):
        res += A[i][j] - min_a
print(res)
