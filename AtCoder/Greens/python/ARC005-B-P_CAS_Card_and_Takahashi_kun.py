X, Y, W = input().split()
X, Y = map(lambda x: int(x) - 1, (X, Y))
C = [list(input()) for _ in range(9)]

dx, dy = {
    'R': (1, 0),
    'L': (-1, 0),
    'U': (0, -1),
    'D': (0, 1),
    "RU": (1, -1),
    "RD": (1, 1),
    "LU": (-1, -1),
    "LD": (-1, 1)
}[W]

res = ""
for i in range(4):
    res += C[Y][X]
    _x = X + dx
    _y = Y + dy
    if _x < 0 or 9 <= _x:
        dx *= -1
        _x = X + dx
    if _y < 0 or 9 <= _y:
        dy *= -1
        _y = Y + dy
    X, Y = _x, _y
print(res)
