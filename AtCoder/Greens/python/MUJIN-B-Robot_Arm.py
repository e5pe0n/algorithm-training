from math import pi
L = list(map(int, input().split()))
R = sum(L)
if sum(L) - max(L) * 2 >= 0:
    r = 0
else:
    r = max(L) * 2 - sum(L)
print(f"{pi * (R * R - r * r):.7f}")
