N = int(input())
A = list(map(int, input().split()))

i = 0
res = 0
while i < N:
    res += 1
    while i + 1 < N and A[i + 1] - A[i] == 0:
        i += 1
    if i >= N - 1:
        break
    d = A[i + 1] - A[i]
    while i + 1 < N and (A[i + 1] - A[i]) * d >= 0:
        i += 1
    i += 1
print(res)
