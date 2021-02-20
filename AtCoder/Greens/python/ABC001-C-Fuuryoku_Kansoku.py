Deg, Dis = map(int, input().split())
Deg *= 10


def f():
    d = ["NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"]
    s = 1125
    t = 2250
    for i in range(15):
        if s <= Deg < s + t:
            return d[i]
        s += t
    return "N"


def g():
    if 0 <= Dis <= 2:
        return 0
    if 3 <= Dis <= 15:
        return 1
    if 16 <= Dis <= 33:
        return 2
    if 34 <= Dis <= 54:
        return 3
    if 55 <= Dis <= 79:
        return 4
    if 80 <= Dis <= 107:
        return 5
    if 108 <= Dis <= 138:
        return 6
    if 139 <= Dis <= 171:
        return 7
    if 172 <= Dis <= 207:
        return 8
    if 208 <= Dis <= 244:
        return 9
    if 245 <= Dis <= 284:
        return 10
    if 285 <= Dis <= 326:
        return 11
    return 12


W = f()
Dis = (Dis * 100 // 60 + 5) // 10
S = g()
if S == 0:
    W = "C"
print(W, S)
