M = 10000
d = [0] * 101


def f(i):
    global d
    if i == 0:
        return 0
    if i == 1:
        return 1
    if d[i] > 0:
        return d[i]
    d[i] = f(i - 1) + f(i - 2)
    return d[i]


print(f(100) % M)
