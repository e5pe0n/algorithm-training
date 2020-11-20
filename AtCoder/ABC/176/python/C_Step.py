N = int(input())
A = list(map(int, input().split()))

res = 0
for i in range(1, N):
    if A[i - 1] > A[i]:
        res += A[i - 1] - A[i]
        A[i] = A[i - 1]
print(res)
