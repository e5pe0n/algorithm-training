N, M = list(map(int, input().split()))
P = [list(map(int, input().split())) for _ in range(N)]
Q = [list(map(int, input().split())) for _ in range(M)]

for i in range(N):
    d = 10 ** 9
    res = 0
    for j in range(M):
        _d = abs(P[i][0] - Q[j][0]) + abs(P[i][1] - Q[j][1])
        if _d < d:
            d = _d
            res = j + 1
    print(res)
