def compress1(s):
    t = s + '_'
    res = []
    cnt = 0
    for i in range(len(t) - 1):
        cnt += 1
        if t[i] != t[i + 1]:
            res.append(t[i])
            res.append(str(cnt))
            cnt = 0
    res = "".join(res)
    return res if len(res) < len(s) else s


def show(f, fn, ss):
    print(f"# {fn}")
    print("\n".join([f"{s} -> {f(s)}" for s in ss]))
    print()


def ns(f):
    return next(f).strip()


with open("../testcases/1_06.txt") as f:
    n = int(ns(f))
    ss = [ns(f) for _ in range(n)]


show(compress1, "compress1", ss)
