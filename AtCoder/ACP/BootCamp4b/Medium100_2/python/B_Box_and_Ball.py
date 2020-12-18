N, M = map(int, input().split())
XY = [list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)]
R = [True] + [False] * (N - 1)
C = [1] * N
for x, y in XY:
    C[x] -= 1
    C[y] += 1
    if R[x]:
        R[y] = True
    if C[x] == 0:
        R[x] = False
res = len(list(filter(lambda x: x, R)))
print(res)
