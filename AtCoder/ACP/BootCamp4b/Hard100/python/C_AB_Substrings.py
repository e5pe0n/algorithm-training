N = int(input())
S = [input() for _ in range(N)]

cnt_AB = 0
cnt_A = 0
cnt_B = 0
cnt_B_A = 0
for s in S:
    n = len(s)
    for i in range(n - 1):
        if s[i:i + 2] == "AB":
            cnt_AB += 1
    if s[0] == "B" and s[-1] == "A":
        cnt_B_A += 1
    elif s[0] == "B":
        cnt_B += 1
    elif s[-1] == "A":
        cnt_A += 1
if cnt_B_A > 0:
    cnt_AB += cnt_B_A - 1
    if cnt_A > 0:
        cnt_AB += 1
        cnt_A -= 1
    if cnt_B > 0:
        cnt_AB += 1
        cnt_B -= 1
cnt_AB += min(cnt_A, cnt_B)
print(cnt_AB)
