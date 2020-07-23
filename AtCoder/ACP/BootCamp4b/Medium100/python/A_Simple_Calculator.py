x, y = list(map(int, input().split()))
if x < y:
    if x < 0 and y > 0:
        res = abs(abs(x) - y) + 1
    else:
        res = y - x
else:
    res = abs(abs(x) - abs(y)) + 1 + int((x < 0 and y < 0) or (x > 0 and y > 0))
print(res)
