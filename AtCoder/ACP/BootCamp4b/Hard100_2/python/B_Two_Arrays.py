N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

diff = 0
t = 0
for i in range(N):
    diff += B[i] - A[i]
    if B[i] > A[i]:
        t += (B[i] - A[i] + 1) // 2
if t <= diff:
    print("Yes")
else:
    print("No")
