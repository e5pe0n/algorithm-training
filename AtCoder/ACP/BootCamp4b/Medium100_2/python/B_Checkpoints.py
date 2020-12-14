INF = float('inf')


N, M = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(N)]
CD = [list(map(int, input().split())) for _ in range(M)]

for i, (a, b) in enumerate(AB):
    min_d = INF
    res = 0
    for j, (c, d) in enumerate(CD):
        d = abs(a - c) + abs(b - d)
        if d < min_d:
            min_d = d
            res = j + 1
    print(res)
