import math


S = int(input())
s = int(math.ceil(S ** 0.5))
remain = s * s - S
t = s
if remain > s:
    remain = s * (s - 1) - S
    t = s - 1
print(0, 0, s, 1, remain, t)
