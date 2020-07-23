W, H, N = list(map(int, input().split()))
x_low, x_up = 0, W
y_low, y_up = 0, H
for _ in range(N):
    x, y, a = list(map(int, input().split()))
    if a == 1:
        x_low = max(x_low, x)
    elif a == 2:
        x_up = min(x_up, x)
    elif a == 3:
        y_low = max(y_low, y)
    else:
        y_up = min(y_up, y)
print(max(0, x_up - x_low) * max(0, y_up - y_low))
