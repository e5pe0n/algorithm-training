N = int(input())
CP = [list(map(int, input().split())) for _ in range(N)]
C1 = [0] * (N + 1)
C2 = [0] * (N + 1)
for i in range(N):
    C1[i + 1] = C1[i]
    C2[i + 1] = C2[i]
    if CP[i][0] == 1:
        C1[i + 1] += CP[i][1]
    else:
        C2[i + 1] += CP[i][1]
Q = int(input())
for _ in range(Q):
    L, R = map(int, input().split())
    print(C1[R] - C1[L - 1], C2[R] - C2[L - 1])
