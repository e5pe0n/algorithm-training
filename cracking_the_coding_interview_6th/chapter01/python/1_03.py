def urlify1(s, n):
    s = s[:n]
    return "".join([c if c != ' ' else "%20" for c in s])


def show(f, fn, ps):
    print(f"# {fn}")
    print("\n".join([f(p[1], p[0]) for p in ps]))
    print("")


def ns(f):
    return next(f).strip()


def parse_input(s):
    lst = []
    for c in s:
        if c in [str(i) for i in range(10)]:
            lst.append(c)
        else:
            break
    n_str = "".join(lst)
    return (int(n_str), s[len(n_str) + 1:-1])  # exclude the last character '\n'


with open("../testcases/1_03.txt") as f:
    n = int(ns(f))
    ps = [parse_input(next(f)) for _ in range(n)]


show(urlify1, "urlify1", ps)
