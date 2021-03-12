N = int(input())
A = list(map(int, input().split()))
res = 1000
for i in range(N - 1):
    cnt = 0
    if A[i + 1] > A[i]:
        cnt = res // A[i]
    res += (A[i + 1] - A[i]) * cnt
print(res)
