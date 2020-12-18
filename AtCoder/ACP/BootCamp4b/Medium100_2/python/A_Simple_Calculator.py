x, y = map(int, input().split())
if x == y:
    res = 0
elif x == -y:
    res = 1
elif x * y < 0:
    res = max(abs(x), abs(y)) - min(abs(x), abs(y)) + 1
elif x == 0:
    if y > 0:
        res = y - x
    else:
        res = x - y + 1
elif y == 0:
    if x > 0:
        res = x - y + 1
    else:
        res = y - x
else:
    if x < y:
        res = y - x
    else:
        res = x - y + 2
print(res)
