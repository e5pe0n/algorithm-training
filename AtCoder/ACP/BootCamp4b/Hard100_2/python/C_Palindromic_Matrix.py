from collections import Counter
H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

C = Counter()
for a in A:
    for _a in a:
        C[_a] += 1
if H > W:
    H, W = W, H
if H == 1:
    odd = 0
    for v in C.values():
        if v % 2 != 0:
            odd += 1
    if H * W % 2 == 0 and odd == 0:
        print("Yes")
    elif H * W % 2 != 0 and odd == 1:
        print("Yes")
    else:
        print("No")
    exit()
four = 0
odd = 0
for v in C.values():
    if v % 2 != 0:
        odd += 1
    if v >= 4:
        four += v // 4
if H * W % 2 == 0 and odd == 0 and four >= (H // 2) * (W // 2):
    print("Yes")
elif H * W % 2 != 0 and odd == 1 and four >= (H // 2) * (W // 2):
    print("Yes")
else:
    print("No")
