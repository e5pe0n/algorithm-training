from math import gcd
A, B, C, D = map(int, input().split())
lcm = C * D // gcd(C, D)
mul_D = B // D - (A - 1) // D
mul_C = B // C - (A - 1) // C
mul_CD = B // lcm - (A - 1) // lcm
res = (B - A + 1) - (mul_D + mul_C - mul_CD)
print(res)
