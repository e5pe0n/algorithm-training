import sys


N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
C = [int(x) for x in input().split()]

A_B = [0] * N
B_C = [0] * N

if N == 1:
    print(int(A[0] < B[0] and B[0] < C[0]))
    sys.exit()

A.sort()
B.sort()
C.sort()

i = 0
idx = 0
while i < N and idx < N:
    while i < N and idx < N and C[i] <= B[idx]:
        i += 1
    while i < N and idx < N and C[i] > B[idx]:
        B_C[idx] = N - i
        idx += 1
i = N - 1
idx = N - 1
while idx > 0:
    while (i >= 0 and idx > 0 and A[idx] >= B[i]) or (i < 0 and idx > 0):
        idx -= 1
        A_B[idx] = A_B[idx + 1]
    while i >= 0 and idx >= 0 and A[idx] < B[i]:
        A_B[idx] += B_C[i]
        i -= 1
ans = sum(A_B)
print(ans)
