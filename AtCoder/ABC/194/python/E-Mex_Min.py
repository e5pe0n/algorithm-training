MAX_N = 1_500_000
N, M = map(int, input().split())
A = list(map(int, input().split()))
P = [[0] for _ in range(MAX_N + 1)]
for i in range(N):
    P[A[i]].append(i + 1)
for i in range(MAX_N + 1):
    P[i].append(N + 1)
for i in range(MAX_N + 1):
    for j in range(len(P[i]) - 1):
        if P[i][j + 1] - P[i][j] > M:
            print(i)
            exit()
