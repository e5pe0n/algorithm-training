import sys


N, M = [int(i) for i in input().split()]
C = [[False] * N for _ in range(N)]
for i in range(M):
    x, y = [int(i) for i in input().split()]
    C[x - 1][y - 1] = True
    C[y - 1][x - 1] = True
    C[x - 1][x - 1] = True
    C[y - 1][y - 1] = True

if M == 0:
    print(1)
    sys.exit()

if M == 1:
    print(2)
    sys.exit()

res = 0
for i in range(2, 1 << N):
    B = format(i, f'0{N}b')
    V = []
    for j in range(N):
        if B[j] == '1':
            V.append(j)
    flg = True
    for v in V:
        for _v in V:
            if not C[v][_v]:
                flg = False
                break
    if flg:
        res = max(res, len(V))
print(res)
