NA, NB, M = list(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))

res = 1_000_000_000
for i in range(M):
    x, y, c = list(map(int, input().split()))
    res = min(A[x - 1] + B[y - 1] - c, res)

res = min(min(A) + min(B), res)
print(res)
