# LTE

S_MAX = 8_000

M = [[1, 0], [0, 1], [-1, 0], [0, -1]]

s = input()
x, y = [int(i) for i in input().split()]
N = len(s)


def f(s, i, d, _x, _y):
    while i < N and s[i] == 'F':
        _x += M[d][0]
        _y += M[d][1]
        i += 1
    if i >= N:
        return _x == x and _y == y
    else:
        res0 = f(s, i + 1, (d + 1) % 4, _x, _y)
        res1 = f(s, i + 1, (d + 3) % 4, _x, _y)
        return res0 or res1


if (f(s, 0, 0, 0, 0)):
    print('Yes')
else:
    print('No')
