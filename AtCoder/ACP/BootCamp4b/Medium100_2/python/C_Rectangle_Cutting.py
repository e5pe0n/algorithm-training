W, H, x, y = map(float, input().split())
res = W * H / 2
print(f"{res:.10f} {int(W / 2 == x and H / 2 == y)}")
