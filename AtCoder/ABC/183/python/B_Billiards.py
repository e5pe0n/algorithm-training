Sx, Sy, Gx, Gy = map(int, input().split())
x = (Gx * Sy + Sx * Gy) / (Gy + Sy)
print(f"{x:.6f}")
