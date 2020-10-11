X, Y, A, B, C = [int(x) for x in input().split()]
V = [(int(x), 'B') for x in input().split()] \
    + [(int(x), 'G')for x in input().split()] \
    + [(int(x), 'N') for x in input().split()]
V.sort(reverse=True)
cnt_B = 0
cnt_G = 0
_V = []
for v in V:
    if v[1] == 'B' and cnt_B < X:
        _V.append(v[0])
        cnt_B += 1
    elif v[1] == 'G' and cnt_G < Y:
        _V.append(v[0])
        cnt_G += 1
    elif v[1] == 'N':
        _V.append(v[0])
    if cnt_B == X and cnt_G == Y:
        break

ans = sum(_V[:X + Y])
print(ans)
