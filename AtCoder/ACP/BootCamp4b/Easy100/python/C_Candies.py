N = int(input())
A = [list(map(int, input().split())) for _ in range(2)]
res = 0
for i in range(N):
    t = 0
    for j in range(i + 1):
        t += A[0][j]
    for j in range(i, N):
        t += A[1][j]
    res = max(res, t)
print(res)
