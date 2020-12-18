from math import gcd
N = int(input())
A = list(map(int, input().split()))


res = gcd(A[0], A[1])
for i in range(2, N):
    res = gcd(res, A[i])
print(res)
