INF = float('inf')


a, b, x, y = map(int, input().split())

if a == b:
    print(x)
    exit()
res = INF
if a < b:
    for i in range(b - a + 1):
        res = min(res, (2 * i + 1) * x + (b - a - i) * y)
else:
    for i in range(a - b):
        res = min(res, (2 * i + 1) * x + (a - b - 1 - i) * y)
print(res)
