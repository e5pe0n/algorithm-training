from math import gcd


K = int(input())
res = 0
for a in range(1, K + 1):
    for b in range(1, K + 1):
        for c in range(1, K + 1):
            res += gcd(a, gcd(b, c))
print(res)
