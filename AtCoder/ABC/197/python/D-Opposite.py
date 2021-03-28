from math import pi, cos, sin
N = int(input())
x0, y0 = map(int, input().split())
x2, y2 = map(int, input().split())


Cx, Cy = (x0 + x2) / 2, (y0 + y2) / 2

theta = 2 * pi / N
x1 = (x0 - Cx) * cos(theta) - (y0 - Cy) * sin(theta) + Cx
y1 = (x0 - Cx) * sin(theta) + (y0 - Cy) * cos(theta) + Cy
print(f"{x1:.6f} {y1:.6f}")
