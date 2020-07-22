N = int(input())
A = [0] + list(map(int, input().split())) + [0]
t = 0
for i in range(N + 1):
    t += abs(A[i] - A[i + 1])
for i in range(1, N + 1):
    if A[i - 1] <= A[i] <= A[i + 1] or A[i - 1] >= A[i] >= A[i + 1]:
        print(t)
    else:
        print(t - abs(A[i - 1] - A[i]) - abs(A[i] - A[i + 1]) + abs(A[i - 1] - A[i + 1]))
