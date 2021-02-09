from math import gcd
N = int(input())
A = list(map(int, input().split()))

G1 = [A[0]] + [0] * N
G2 = [0] * N + [A[N - 1]]
for i in range(N):
    G1[i + 1] = gcd(G1[i], A[i])
    G2[N - i - 1] = gcd(G2[N - i], A[N - i - 1])
res = 0
for i in range(N):
    if i == 0:
        res = max(res, G2[i + 1])
    elif i == N - 1:
        res = max(res, G1[i])
    else:
        res = max(res, gcd(G1[i], G2[i + 1]))
print(res)
