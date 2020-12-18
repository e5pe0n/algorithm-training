from math import atan, degrees
a, b, x = map(int, input().split())
V = a * a * b / 2
if x == V * 2:
    res = 90
elif x <= V:
    res = degrees(atan(2 * x / (a * b * b)))
else:
    res = 90 - degrees(atan((2 * a * a * b - 2 * x) / (a ** 3)))
print(f"{90 - res:.7f}")
