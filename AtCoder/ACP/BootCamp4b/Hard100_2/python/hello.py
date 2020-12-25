def f(n):
    if n < 2:
        return 1
    return n * f(n - 2)


def cnt(n):
    ns = str(n)
    cnt = 0
    for s in ns[::-1]:
        if s == '0':
            cnt += 1
        else:
            break
    return cnt


for i in range(1001):
    print(f"({i}) {cnt(f(i))}")
