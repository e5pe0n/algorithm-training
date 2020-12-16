N = int(input())
A = [0] + list(map(int, input().split())) + [0]

sm = 0
for i in range(N + 1):
    sm += abs(A[i + 1] - A[i])
for i in range(1, N + 1):
    res = sm
    if not(A[i + 1] <= A[i] <= A[i - 1] or A[i + 1] >= A[i] >= A[i - 1]):
        res += -(abs(A[i + 1] - A[i]) + abs(A[i] - A[i - 1])) + abs(A[i + 1] - A[i - 1])
    print(res)
