N = int(input())
A = list(map(int, input().split()))

res = 0
for i in range(N):
    min_a = A[i]
    for j in range(i, N):
        min_a = min(min_a, A[j])
        res = max(res, min_a * (j - i + 1))
print(res)
