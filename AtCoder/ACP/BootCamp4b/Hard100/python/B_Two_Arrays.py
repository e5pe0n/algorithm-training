N = int(input())
A = [int(x) for x in input().split()]
B = [int(x) for x in input().split()]
n = sum(B) - sum(A)
for i in range(N):
    if A[i] - B[i] < 0:
        n -= (B[i] - A[i] + 1) // 2
if n >= 0:
    print("Yes")
else:
    print("No")
