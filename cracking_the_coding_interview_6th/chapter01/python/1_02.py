def is_perm1(s, t):
    if len(s) != len(t):
        return False
    s2 = sorted(s)
    t2 = sorted(t)
    return s2 == t2


def is_perm2(s, t):
    if len(s) != len(t):
        return False
    cnt = [0] * 255
    for c in s:
        cnt[ord(c)] += 1
    for c in t:
        cnt[ord(c)] -= 1
        if cnt[ord(c)] < 0:
            return False
    return True


def show(f, fn, ss):
    print(f"# {fn}")
    line = "{} is {} of {}"
    print("\n".join([line.format(s, "permutation" if f(
        s, t) else "not permutation", t) for s, t in ss]))
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/1_02.txt") as f:
    n = int(ns(f))
    ss = [ns(f).split() for _ in range(n)]

show(is_perm1, "is_perm1", ss)
show(is_perm2, "is_perm2", ss)
