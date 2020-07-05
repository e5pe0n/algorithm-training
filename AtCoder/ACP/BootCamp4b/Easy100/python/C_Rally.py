MAX_N = 100
MAX_X = 100
INF = 1_000_000_000

N = int(input())
X = list(map(int, input().split()))

res = INF
for i in range(1, MAX_X + 1):
    t = 0
    for x in X:
        t += (i - x) ** 2
    res = min(res, t)
print(res)
