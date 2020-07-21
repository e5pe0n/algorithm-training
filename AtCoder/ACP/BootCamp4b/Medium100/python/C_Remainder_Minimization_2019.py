import math
INF = 2_000_000_001
L, R = list(map(int, input().split()))
if math.ceil(L / 2019) <= R // 2019:
    print(0)
else:
    res = INF
    for i in range(L % 2019, R % 2019):
        for j in range(L % 2019 + 1, R % 2019 + 1):
            res = min(res, (i * j) % 2019)
    print(res)
