N, K, M = map(int, input().split())
sm = sum(list(map(int, input().split())))
res = N * M - sm
res = max(res, 0)
if res > K:
    res = -1
print(res)
