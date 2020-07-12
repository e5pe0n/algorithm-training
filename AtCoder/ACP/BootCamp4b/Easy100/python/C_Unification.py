S = input()
cnt = 0
_cnt = 0
for s in S:
    if s == '0':
        cnt += 1
    else:
        _cnt += 1
print(min(cnt, _cnt) * 2)
