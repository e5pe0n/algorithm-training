H, W = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(H)]


R = [0] * H
C = [0] * W
for i in range(H):
    for j in range(W):
        R[i] += A[i][j]
        C[j] += A[i][j]

for i in range(H):
    print(" ".join(str(R[i] + C[j] - A[i][j]) for j in range(W)))
