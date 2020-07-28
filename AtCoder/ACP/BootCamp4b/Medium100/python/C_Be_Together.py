INF = 10 ** 18
N = int(input())
A = list(map(int, input().split()))
up = max(A)
low = min(A)
res = INF
for i in range(low, up + 1):
    t = 0
    for a in A:
        t += (i - a) ** 2
    res = min(res, t)
print(res)
