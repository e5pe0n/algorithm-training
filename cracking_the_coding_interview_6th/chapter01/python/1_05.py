def insertable(s, t):
    i_s, i_t = 0, 0
    while i_s < len(s) and i_t < len(t):
        if s[i_s] != t[i_t]:
            i_t += 1
            if i_t - i_s >= 2:
                return False
        else:
            i_s += 1
            i_t += 1
    return True


def editable(s, t):
    diff = 0
    for _s, _t in zip(s, t):
        if _s != _t:
            diff += 1
            if diff >= 2:
                return False
    return True


def is_one_way1(s, t):
    if len(s) > len(t):
        s, t = t, s
    d = len(t) - len(s)
    if d >= 2:
        return False
    elif d == 1:
        return insertable(s, t)
    else:
        return editable(s, t)


def is_one_way2(s, t):
    if len(s) > len(t):
        s, t = t, s
    d = len(t) - len(s)
    if d >= 2:
        return False
    i_s, i_t = 0, 0
    diff = 0
    while i_s < len(s) and i_t < len(t):
        if s[i_s] != t[i_t]:
            diff += 1
            if diff >= 2:
                return False
            if d == 0:
                i_s += 1
                i_t += 1
            else:
                i_t += 1
        else:
            i_s += 1
            i_t += 1
    return True


def show(f, fn, ss):
    print(f"# {fn}")
    print("\n".join([f"{s}, {t} -> {'true' if f(s, t) else 'false'}" for s, t in ss]))
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/1_05.txt") as f:
    n = int(ns(f))
    ss = [ns(f).split() for _ in range(n)]


show(is_one_way1, "is_one_way1", ss)
show(is_one_way2, "is_one_way2", ss)
