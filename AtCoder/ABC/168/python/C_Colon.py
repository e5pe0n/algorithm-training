from math import pi, cos


A, B, H, M = map(int, input().split())
theta_A = 2 * pi * H / 12 + 2 * pi * M / (12 * 60)
theta_B = 2 * pi * M / 60
res = A * A + B * B - 2 * A * B * cos(theta_A - theta_B)
print(f"{res ** 0.5:.10f}")
