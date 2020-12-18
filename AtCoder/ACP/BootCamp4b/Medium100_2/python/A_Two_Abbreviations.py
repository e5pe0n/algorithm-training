from math import gcd
N, M = map(int, input().split())
S = input()
T = input()
if N > M:
    N, M = M, N
    S, T = T, S
g = gcd(N, M)
res = N * M // gcd(N, M)
n = N // g
m = M // g
for i in range(N):
    if i * m % n == 0 and i * m // n < M and S[i] != T[i * m // n]:
        res = -1
        break
print(res)
