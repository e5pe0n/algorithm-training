X = input()
M = int(input())


def is_less(b):
    t = 0
    for x in X:
        t = t * b + int(x)
        if t > M:
            return False
    return True


if len(X) == 1:
    if int(X[0]) > M:
        print(0)
        exit()
    else:
        print(1)
        exit()

d = max(list(map(int, X)))
if not is_less(d + 1):
    print(0)
    exit()

ub = 10**18 + 1
lb = d + 1
while ub - lb > 1:
    md = (ub + lb) // 2
    if is_less(md):
        lb = md
    else:
        ub = md
print(lb - d)
