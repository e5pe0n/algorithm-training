N = int(input())
_t, _x, _y = 0, 0, 0
flg = True
for i in range(N):
    t, x, y = list(map(int, input().split()))
    dt = t - _t
    dd = abs(x - _x) + abs(y - _y)
    if not (dd <= dt and dt % 2 == dd % 2):
        flg = False
    _t, _x, _y = t, x, y
if flg:
    print('Yes')
else:
    print('No')
