from math import pi, cos, sin, acos, degrees
N, M = map(int, input().split())
S = N * 2 * pi / 12 + M * 2 * pi / 60 / 12
L = M * 2 * pi / 60
rad = cos(S) * cos(L) + sin(S) * sin(L)
deg = degrees(acos(rad))
if deg < 0:
    deg += 360
print(f"{min(deg, 360 - deg):.5f}")
