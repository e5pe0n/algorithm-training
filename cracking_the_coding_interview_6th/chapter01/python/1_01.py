def is_unique1(s):
    for i in range(len(s) - 1):
        for j in range(1, len(s)):
            if s[i] == s[j]:
                return False
    return True


def is_unique2(s):
    return len(set(s)) == len(s)


def is_unique3(s):
    bs = [False] * 255
    for c in s:
        i = ord(c)
        if bs[i]:
            return False
        bs[i] = True
    return True


def is_unique4(s):
    s2 = sorted(s)
    for i in range(len(s2) - 1):
        if s2[i + 1] == s2[i]:
            return False
    return True


def is_unique5(s):
    b = 0
    for c in s:
        i = ord(c)
        if b & (1 << i):
            return False
        b |= 1 << i
    return True


def show(f, fn, ss):
    print(f"# {fn}")
    pre = "{} is {}"
    print("\n".join([pre.format(s, "unique" if f(s) else "not unique") for s in ss]))
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/1_01.txt") as f:
    n = int(ns(f))
    ss = [ns(f) for _ in range(n)]

show(is_unique1, "is_unique1", ss)
show(is_unique2, "is_unique2", ss)
show(is_unique3, "is_unique3", ss)
show(is_unique4, "is_unique4", ss)
show(is_unique5, "is_unique5", ss)
