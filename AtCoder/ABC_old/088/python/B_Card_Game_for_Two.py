N = int(input())
A = [int(i) for i in input().split()]
A.sort()
res = 0
for i in range(N - 1, -1, -2):
    res += A[i]
for i in range(N - 2, -1, -2):
    res -= A[i]
print(res)
