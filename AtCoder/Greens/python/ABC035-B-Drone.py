S = input()
T = int(input())
h, w, q = 0, 0, 0
for s in S:
    if s == 'L':
        w -= 1
    elif s == 'R':
        w += 1
    elif s == 'U':
        h += 1
    elif s == 'D':
        h -= 1
    else:
        q += 1
if T == 1:
    res = abs(h) + abs(w) + q
else:
    res = abs(h) + abs(w) - q
    if res < 0:
        res = abs(res) % 2
print(res)
