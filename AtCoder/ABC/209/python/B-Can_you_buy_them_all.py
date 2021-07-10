N, X = map(int, input().split())
A = list(map(int, input().split()))
for i in range(N):
    if i % 2 != 0:
        A[i] -= 1

if X >= sum(A):
    print("Yes")
else:
    print("No")
