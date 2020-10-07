MOD = 1_000_000_007


N = int(input())
A = [int(x) for x in input().split()]

A.sort()
start = 0
t = 1
if N % 2 != 0:
    if A[0] != 0:
        t = 0
    else:
        start = 1
for i in range(start, N, 2):
    if A[i] == i + 1 and A[i + 1] == i + 1:
        t *= 2
    else:
        t = 0
        break
print(t % MOD)
