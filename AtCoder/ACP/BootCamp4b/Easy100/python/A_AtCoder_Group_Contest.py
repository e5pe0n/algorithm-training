N = int(input())
A = list(map(int, input().split()))
A.sort()
res = 0
for i in range(3 * N - 2, 3 * N - 2 - 2 * (N - 1) - 1, -2):
    res += A[i]
print(res)
