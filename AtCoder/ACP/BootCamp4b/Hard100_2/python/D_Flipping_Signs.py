INF = float('inf')
N = int(input())
A = list(map(int, input().split()))

res = 0
cnt = 0
min_a = INF
for a in A:
    if a < 0:
        cnt += 1
    a = abs(a)
    res += a
    min_a = min(min_a, a)
if cnt % 2 != 0:
    res -= min_a * 2
print(res)
