INF = float('inf')
N = int(input())
A = list(map(int, input().split()))

res = INF
for i in range(1 << (N - 1)):
    xored = 0
    ored = 0
    for j in range(N):
        ored |= A[j]
        if i >> j & 1:
            xored ^= ored
            ored = 0
    xored ^= ored
    res = min(res, xored)
print(res)
