from math import gcd
N, K = map(int, input().split())
A = list(map(int, input().split()))

if N == 1:
    res = A[0] == K
else:
    g = gcd(A[0], A[1])
    for i in range(2, N):
        g = gcd(g, A[i])
    max_a = max(A)
    res = max_a >= K and (max_a % K) % g == 0
if res:
    print("POSSIBLE")
else:
    print("IMPOSSIBLE")
