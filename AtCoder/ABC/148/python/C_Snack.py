from math import gcd
A, B = map(int, input().split())
res = A // gcd(A, B) * B
print(res)
