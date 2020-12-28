N = int(input())
S = [input() for _ in range(N)]

res = 0
cnt_BA = 0
cnt_B = 0
cnt_A = 0
for s in S:
    if s[0] == 'B' and s[-1] == 'A':
        cnt_BA += 1
    elif s[0] == 'B':
        cnt_B += 1
    elif s[-1] == 'A':
        cnt_A += 1
    for i in range(len(s) - 1):
        if s[i] == 'A' and s[i + 1] == 'B':
            res += 1
if cnt_BA > 0:
    res += cnt_BA - 1
    if cnt_B > 0:
        res += 1
        cnt_B -= 1
    if cnt_A > 0:
        res += 1
        cnt_A -= 1
res += min(cnt_B, cnt_A)
print(res)
