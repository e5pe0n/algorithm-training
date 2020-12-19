N = int(input())
A = sorted(list(map(int, input().split())))

res = 0
for i in range(N - 1):
    res += (A[i + 1] - A[i]) * (N - (i + 1)) * (i + 1)
print(res)
