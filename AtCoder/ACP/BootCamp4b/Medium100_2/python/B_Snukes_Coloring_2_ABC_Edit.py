W, H, N = map(int, input().split())
left = 0
right = W
top = H
bottom = 0
for _ in range(N):
    x, y, a = map(int, input().split())
    if a == 1:
        left = max(left, x)
    elif a == 2:
        right = min(right, x)
    elif a == 3:
        bottom = max(bottom, y)
    else:
        top = min(top, y)
res = max(0, top - bottom) * max(0, right - left)
print(res)
