import sys
N, M = list(map(int, input().split()))
S = input()
T = input()
if S[0] != T[0]:
    print(-1)
    sys.exit()
if N > M:
    N, M = M, N
    S, T = T, S


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


L = N * M // gcd(N, M)
n = L // N
m = L // M
l = n * m // gcd(n, m)
for i in range(l, L, l):
    if S[i // n] != T[i // m]:
        print(-1)
        sys.exit()
print(L)
