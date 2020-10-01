def f(n):
    if n < 2:
        return 1
    return n * f(n - 2)


def cnt(n):
    c = 0
    for i in str(n)[::-1]:
        if i == '0':
            c += 1
        else:
            break
    return c


for i in range(10, 300, 10):
    print(i, cnt(f(i)))
