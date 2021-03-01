N = int(input())
d = [[False] * N for _ in range(N)]
cnt = 0
for i in range(1, N):
    for j in range(i + 1, N + 1):
        if N % 2 != 0 and i + j == N:
            continue
        if N % 2 == 0 and i + j == N + 1:
            continue
        d[i - 1][j - 1] = True
        cnt += 1
print(cnt)
for i in range(N - 1):
    for j in range(i + 1, N):
        if d[i][j]:
            print(i + 1, j + 1)
