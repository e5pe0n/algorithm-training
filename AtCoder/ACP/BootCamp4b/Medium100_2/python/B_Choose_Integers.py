from math import gcd
A, B, C = map(int, input().split())
g = gcd(A, B)
if C % g == 0:
    print("YES")
else:
    print("NO")
