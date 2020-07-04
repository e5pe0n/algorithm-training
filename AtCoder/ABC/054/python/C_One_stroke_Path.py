from itertools import permutations


N, M = [int(i) for i in input().split()]
D = [[False] * N for _ in range(N)]
for _ in range(M):
    a, b = [int(i) for i in input().split()]
    D[a - 1][b - 1] = True
    D[b - 1][a - 1] = True
perm = [[0] + list(p) for p in list(permutations(range(1, N)))]

cnt = 0
for p in perm:
    flg = True
    for i in range(N - 1):
        if not D[p[i]][p[i + 1]]:
            flg = False
            break
    if flg:
        cnt += 1
print(cnt)
