N, M = map(int, input().split())
A = [list(input()) for _ in range(N)]
B = [list(input()) for _ in range(M)]

for i in range(N - M + 1):
    for j in range(N - M + 1):
        f = True
        for _i in range(M):
            for _j in range(M):
                if A[i + _i][j + _j] != B[_i][_j]:
                    f = False
        if f:
            print("Yes")
            exit()
print("No")
