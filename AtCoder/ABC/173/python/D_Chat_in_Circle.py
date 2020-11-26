N = int(input())
A = list(map(int, input().split()))
A.sort()
res = A[N - 1]
j = N - 2
cnt = 0
for i in range(N - 3, -1, -1):
    res += A[j]
    cnt += 1
    if cnt % 2 == 0:
        j -= 1
print(res)
