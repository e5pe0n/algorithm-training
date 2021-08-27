H, W = map(int, input().split())
if H == 1 or W == 1:
    res = H * W
else:
    res = ((H + 1) // 2) * ((W + 1) // 2)
print(res)
