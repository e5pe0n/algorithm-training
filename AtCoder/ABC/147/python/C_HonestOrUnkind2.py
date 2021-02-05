N = int(input())
A = []
for _ in range(N):
    a = int(input())
    XY = []
    for _ in range(a):
        x, y = map(int, input().split())
        XY.append((x - 1, y))
    A.append(XY)

res = 0
for i in range(1 << N):
    cnt = 0
    f = True
    for j in range(N):
        if i >> j & 1:
            cnt += 1
            for x, y in A[j]:
                if (i >> x & 1) != y:
                    f = False
    if f:
        res = max(res, cnt)
print(res)
