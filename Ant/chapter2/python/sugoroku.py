def ns(f):
    return next(f).strip()


with open("../testset/sugoroku/test1.txt", 'r') as f:
    a, b = map(int, ns(f).split())


def extgcd(a, b, x, y):
    d = a
    if b != 0:
        d = extgcd(b, a % b, y, x)
        y[0] -= (a // b) * x[0]
    else:
        x[0] = 1
        y[0] = 0
    return d


x, y = [0], [0]
res = extgcd(a, b, x, y)
x, y = x[0], y[0]
if res != 1:
    print("-1")
else:
    if x >= 0:
        print(f"{x} 0 ", end='')
    else:
        print(f"0 {-x} ", end='')
    if y >= 0:
        print(f"{y} 0")
    else:
        print(f"0 {-y}")
