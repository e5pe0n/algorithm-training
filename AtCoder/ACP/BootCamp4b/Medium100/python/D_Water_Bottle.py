import math
a, b, x = list(map(float, input().split()))
if x <= 0.5 * a * a * b:
    res = math.degrees(math.atan(2 * x / (a * b * b)))
elif x < a * a * b:
    res = math.degrees(math.atan(a / (2 * (b - x / a ** 2))))
else:
    res = 90.0
print(f'{90 - res:.7f}')
