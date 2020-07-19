S = input()
cnt_a = 0
cnt_b = 0
cnt_c = 0
for s in S:
    if s == 'a':
        cnt_a += 1
    elif s == 'b':
        cnt_b += 1
    else:
        cnt_c += 1
if abs(cnt_a - cnt_b) <= 1 and abs(cnt_b - cnt_c) <= 1 and abs(cnt_c - cnt_a) <= 1:
    print('YES')
else:
    print('NO')
