N, M = list(map(int, input().split()))
C = [1] * (N + 1)
B = [True, True] + [False] * (N - 1)
flg = False
for _ in range(M):
    x, y = list(map(int, input().split()))
    if B[x]:
        B[y] = True
    if x == 1 and not flg and C[1] == 1:
        B[1] = False
        flg = True
    if y == 1 and not flg:
        flg = True
    C[x] -= 1
    C[y] += 1
    if C[x] == 0:
        B[x] = False
res = 0
for i in range(1, N + 1):
    if B[i] and C[i] > 0:
        res += 1
print(res)
