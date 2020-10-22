from functools import partial
printf = partial(print, flush=True)

V = "Vacant"


N = int(input())
left_idx = 0
right_idx = N - 1
mid_idx = (left_idx + right_idx) // 2
printf(left_idx)
left = input()
printf(right_idx)
right = input()
if left == V or right == V:
    exit()
while True:
    printf(mid_idx)
    mid = input()
    if mid == V:
        exit()
    elif ((mid_idx - left_idx) % 2 == 0 and left != mid) or ((mid_idx - left_idx) % 2 != 0 and left == mid):
        right_idx = mid_idx
        right = mid
    else:
        left_idx = mid_idx
        left = mid
    mid_idx = (left_idx + right_idx) // 2
