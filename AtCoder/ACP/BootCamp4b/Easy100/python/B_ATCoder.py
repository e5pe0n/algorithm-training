S = input()
cnt = 0
res = 0
for s in S:
    if s in ('A', 'C', 'G', 'T'):
        cnt += 1
    else:
        res = max(res, cnt)
        cnt = 0
print(max(res, cnt))
