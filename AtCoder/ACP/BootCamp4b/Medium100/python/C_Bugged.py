import sys
N = int(input())
S = [int(input()) for _ in range(N)]
t = sum(S)
if t % 10 != 0:
    print(t)
    sys.exit()

res = 0
for s in S:
    if (t - s) % 10 != 0:
        res = max(res, t - s)
print(res)
