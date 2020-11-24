N = int(input())
C = input()
cnt_W = 0
cnt_R = 0
for c in C:
    if c == 'W':
        cnt_W += 1
    else:
        cnt_R += 1
res = 0
for c in C[:cnt_R]:
    if c == 'W':
        res += 1
print(res)
