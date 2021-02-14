INF = float('inf')
di = [0, 1, 0, -1]
dj = [1, 0, -1, 0]
N, M = map(int, input().split())
B = [list(map(int, input())) for _ in range(N)]
res = [[0] * M for _ in range(N)]
for i in range(1, N - 1):
    for j in range(1, M - 1):
        cnt = 0
        mi = INF
        for _di, _dj in zip(di, dj):
            _i = i + _di
            _j = j + _dj
            if B[_i][_j] > 0:
                mi = min(mi, B[_i][_j])
                cnt += 1
        if cnt == 4:
            for _di, _dj in zip(di, dj):
                _i = i + _di
                _j = j + _dj
                B[_i][_j] -= mi
            res[i][j] = mi
print('\n'.join(''.join(list(map(str, r))) for r in res))
