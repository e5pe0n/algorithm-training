N = int(input())
A = [int(x) for x in input().split()]

A.sort()
cnt = 0
for i in range(N - 1):
    if A[i] * 2 >= A[i + 1]:
        cnt += 1
    else:
        cnt = 0
    A[i + 1] += A[i]

print(cnt + 1)
