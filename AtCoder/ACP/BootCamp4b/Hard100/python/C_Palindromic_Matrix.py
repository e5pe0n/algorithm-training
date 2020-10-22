M = 26
H, W = map(int, input().split())
A = [input() for _ in range(H)]
C = [0] * M
for a in A:
    for c in a:
        C[ord(c) - ord('a')] += 1

cnt_odd = 0
cnt_4 = 0
for c in C:
    if c % 2 != 0:
        cnt_odd += 1
    cnt_4 += c // 4

if H * W % 2 != 0:
    if cnt_odd == 1 and cnt_4 >= (H // 2) * (W // 2):
        print("Yes")
    else:
        print("No")
else:
    if cnt_odd == 0 and cnt_4 >= (H // 2) * (W // 2):
        print("Yes")
    else:
        print("No")
