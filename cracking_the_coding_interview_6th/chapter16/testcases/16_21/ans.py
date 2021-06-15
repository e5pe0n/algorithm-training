def ns(f):
    return next(f).strip()


with open("03.txt") as f:
    n1, n2 = map(int, ns(f).split())
    a = list(map(int, ns(f).split()))
    b = list(map(int, ns(f).split()))

sa = sum(a)
sb = sum(b)
for _a in a:
    for _b in b:
        if sa - _a + _b == sb - _b + _a:
            print(_a, _b)
