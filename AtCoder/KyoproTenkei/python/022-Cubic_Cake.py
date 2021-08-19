from math import gcd
A, B, C = map(int, input().split())
g = gcd(A, gcd(B, C))
res = (A // g - 1) + (B // g - 1) + (C // g - 1)
print(res)
