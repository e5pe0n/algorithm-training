MAX_S = 100


N = int(input())
S = [int(input()) for _ in range(N)]

min_s = MAX_S
for s in S:
    if s % 10 != 0:
        min_s = min(min_s, s)

res = sum(S)
if res % 10 == 0:
    res -= min_s
if res % 10 == 0:
    res = 0
print(res)
