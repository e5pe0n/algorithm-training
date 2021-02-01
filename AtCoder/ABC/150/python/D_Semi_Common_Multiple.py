from math import gcd
N, M = map(int, input().split())
A = list(map(int, input().split()))

cnt = 0
a0 = A[0]
while a0 % 2 == 0:
    a0 //= 2
    cnt += 1
lcm = A[0]
f = True
for a in A:
    t = 0
    while a % 2 == 0:
        a //= 2
        t += 1
    if t != cnt:
        f = False
    lcm = lcm // gcd(lcm, a) * a
res = 0
if f:
    res = (M // (lcm // 2) + 2 - 1) // 2
print(res)
