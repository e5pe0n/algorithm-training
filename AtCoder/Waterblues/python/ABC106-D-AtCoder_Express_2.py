N, M, Q = map(int, input().split())
Li = [0] * (N + 1)
Ri = [0] * (N + 1)
cnt = [[0] * (N + 1) for _ in range(N + 1)]
C = [[0] * (N + 1) for _ in range(N + 1)]
for _ in range(M):
    L, R = map(int, input().split())
    Li[L] += 1
    Ri[R] += 1
    C[L][R] += 1
ML = M
for i in range(1, N + 1):
    MR = ML
    for j in range(N, i - 1, -1):
        cnt[i][j] = MR
        MR = max(0, MR - Ri[j])
    ML = max(0, ML - Li[i])
    for j in range(i, N + 1):
        Ri[j] -= C[i][j]
for _ in range(Q):
    p, q = map(int, input().split())
    print(cnt[p][q])
