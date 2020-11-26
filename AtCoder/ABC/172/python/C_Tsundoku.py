from bisect import bisect

INF = float('inf')


N, M, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

sum_A = [0] * (N + 1)
for i, a in enumerate(A):
    sum_A[i + 1] = sum_A[i] + a
sum_B = [0] * (M + 1) + [INF]
for i, b in enumerate(B):
    sum_B[i + 1] = sum_B[i] + b

res = 0
for i in range(N + 1):
    if K - sum_A[i] >= 0:
        j = bisect(sum_B, K - sum_A[i])
        res = max(res, i + j - 1)
print(res)
