N = int(input())
A = list(map(int, input().split()))

sumA = sum(A)
sum_sqareA = sum(list(map(lambda x: x*x, A)))
res = sum_sqareA * (N - 1)
for i in range(N):
    sumA -= A[i]
    res -= 2 * A[i] * sumA
print(res)
