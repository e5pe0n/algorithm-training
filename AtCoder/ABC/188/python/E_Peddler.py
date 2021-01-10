INF = float('inf')
N, M = map(int, input().split())
A = list(map(int, input().split()))
XY = sorted([list(map(lambda x: int(x) - 1, input().split())) for _ in range(M)])

B = A[::]
res = -INF
for x, y in XY:
    res = max(res, A[y] - B[x])
    B[y] = min(B[x], B[y])
print(res)
