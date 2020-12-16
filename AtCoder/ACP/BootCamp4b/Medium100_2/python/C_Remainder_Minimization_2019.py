INF = float('inf')
L, R = map(int, input().split())
res = INF
if R - L >= 2019:
    res = 0
else:
    for i in range(L, R):
        for j in range(i + 1, R + 1):
            res = min(res, i % 2019 * j % 2019 % 2019)
print(res)
