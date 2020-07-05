import sys
H, W = list(map(int, input().split()))
if H == 1 or W == 1:
    print('1')
    sys.exit()
a = (W + 1) // 2
res = W * (H // 2) + (H % 2) * a
print(res)
