N, M = [int(i) for i in input().split()]
R = [0 for _ in range(N)]
for _ in range(M):
    a, b = [int(i) for i in input().split()]
    R[a - 1] += 1
    R[b - 1] += 1
for i in range(N):
    print(R[i])
