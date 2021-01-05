N = int(input())
XY = [None for _ in range(N)]
for i in range(N):
    a = int(input())
    xy = [list(map(int, input().split())) for _ in range(a)]
    XY[i] = xy

res = 0
for i in range(1 << N):
    f = True
    cnt = 0
    for j in range(N):
        if not (i >> j & 1):
            continue
        cnt += 1
        for x, y in XY[j]:
            if (i >> (x - 1) & 1) != y:
                f = False
                break
    if f:
        res = max(res, cnt)
print(res)
