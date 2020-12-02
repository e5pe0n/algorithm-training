INF = float('inf')


N, M, X = map(int, input().split())
C = []
A = []
for _ in range(N):
    c, *a = map(int, input().split())
    C.append(c)
    A.append(a)

res = INF
for i in range(1, 1 << N):
    c = 0
    T = [0] * M
    for j in range(N):
        if i >> j & 1:
            c += C[j]
            for k in range(M):
                T[k] += A[j][k]
    if all(map(lambda x: x >= X, T)):
        res = min(res, c)
if res == INF:
    res = -1
print(res)
