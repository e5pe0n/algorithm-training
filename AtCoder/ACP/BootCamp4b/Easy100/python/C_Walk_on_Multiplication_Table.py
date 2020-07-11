import math
N = int(input())
res = N
for i in range(1, int(math.sqrt(N)) + 1):
    j = N // i
    if j * i == N:
        res = min(res, j - 1 + i - 1)
print(res)
