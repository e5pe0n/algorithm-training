MAX_R = 10**9
N, M = map(int, input().split())
L0, R0 = 1, MAX_R
if N == 1 and M == 0:
    print(L0, R0)
    exit()
if not (0 <= M <= N - 2):
    print(-1)
    exit()
print(L0, R0)
L, R = 2, 3
for i in range(M):
    print(L, R)
    L = R + 1
    R = L + 1
R = R0 - 1
print(L, R)
for i in range(N - M - 2):
    L += 1
    R -= 1
    print(L, R)
