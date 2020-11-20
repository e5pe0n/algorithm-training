N, M, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A = [0] + A
B = [0] + B
for i in range(N):
    A[i + 1] += A[i]
for i in range(M):
    B[i + 1] += B[i]

res, j = 0, M
for i in range(N + 1):
    if A[i] > K:
        break
    while B[j] > K - A[i]:
        j -= 1
    res = max(res, i + j)
print(res)
