from functools import partial
sv = "Vacant"
p = partial(print, flush=True)
N = int(input())
left = 0
right = N - 1
p(left)
left_s = input()
p(right)
right_s = input()
if left_s == sv or right_s == sv:
    exit()
while True:
    mid = (left + right) // 2
    p(mid)
    mid_s = input()
    if mid_s == sv:
        exit()
    if ((mid - left) % 2 == 0 and mid_s == left_s) or ((mid - left) % 2 != 0 and mid_s != left_s):
        left = mid
        left_s = mid_s
    else:
        right = mid
        right_s = mid_s
