H, W = map(int, input().split())
if H % 3 == 0 or W % 3 == 0:
    print(0)
    exit()
res = H * ((W + 3 - 1) // 3) - H * (W // 3)
res = min(res, ((H + 3 - 1) // 3) * W - (H // 3) * W)
for i in range(1, H):
    top = W * i
    left = (H - i) * ((W + 2 - 1) // 2)
    right = (H - i) * (W // 2)
    res = min(res, max((top, left, right)) - min((top, left, right)))
for j in range(1, W):
    left = H * j
    top = (H + 2 - 1) // 2 * (W - j)
    btm = H // 2 * (W - j)
    res = min(res, max((left, top, btm)) - min((left, top, btm)))
print(res)
