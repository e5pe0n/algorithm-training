from math import gcd
N = int(input())
T = [int(input()) for _ in range(N)]
if N == 1:
    print(T[0])
    exit()
lcm = T[0] // gcd(T[0], T[1]) * T[1]
for t in T[2:]:
    lcm = lcm // gcd(lcm, t) * t
print(lcm)
